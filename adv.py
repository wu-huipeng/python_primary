import cv2 as cv
import numpy as np
import torch
import torch.nn
import torch.optim
from torch.autograd import Variable
import torch.utils.data as data
from sklearn.preprocessing import Normalizer
import matplotlib.pyplot as plt
device = torch.device("cuda:0")
label = []
data_x = np.empty((1776,1,64,64),dtype='float32')
count = 0
for i in range(1,1036):
    filename = './my_faces/{}.jpg'.format(i)
    img = cv.imread(filename,0)
    img = Normalizer().fit_transform(img)
    arr = np.asarray(img, dtype="float32")
    data_x[count, :, :, :] = arr
    count += 1
    label.append(0)
for i in range(0,741):

    filename = './other/{}.jpg'.format(i)
    img = cv.imread(filename,0)
    img = Normalizer().fit_transform(img)
    arr = np.asarray(img, dtype="float32")
    data_x[count, :, :, :] = arr
    count += 1
    label.append(1)


label = np.array(label)

data_x = torch.from_numpy(data_x)
label = torch.from_numpy(label)

dataset = torch.utils.data.TensorDataset(data_x,label)

loader = torch.utils.data.DataLoader(dataset,shuffle=True,batch_size=48)

class CNN(torch.nn.Module):

    def __init__(self):
        super(CNN, self).__init__()
        self.layer1 = torch.nn.Sequential(
            torch.nn.Conv2d(1,16,kernel_size=3,stride=1,padding=1),
            torch.nn.ReLU(inplace=True),
            torch.nn.MaxPool2d(kernel_size=2,stride=2),
            torch.nn.Conv2d(16,32,kernel_size=3,stride=1,padding=1),
            torch.nn.ReLU(inplace=True),
            torch.nn.MaxPool2d(kernel_size=2,stride=2),
            torch.nn.Conv2d(32, 64, kernel_size=3, stride=1, padding=1),
            torch.nn.ReLU(inplace=True),
            torch.nn.Conv2d(64, 128, kernel_size=3, stride=1, padding=1),
            torch.nn.ReLU(inplace=True),
            torch.nn.Conv2d(128, 256, kernel_size=3, stride=1, padding=1),
            torch.nn.ReLU(inplace=True),
            torch.nn.MaxPool2d(kernel_size=2,stride=2),

        )
        self.layer2 = torch.nn.Sequential(
            torch.nn.Dropout(),
            torch.nn.Linear(256*8*8,2048),
            torch.nn.ReLU(inplace=True),
            torch.nn.Dropout(),
            torch.nn.Linear(2048,2048),
            torch.nn.ReLU(inplace=True),
            torch.nn.Linear(2048,2)

        )
    def forward(self, x):
        x = self.layer1(x)
        x = x.view(x.size(0),-1)
        x = self.layer2(x)
        return x


cnn = CNN()
optimizers = torch.optim.Adam(cnn.parameters())
losses = torch.nn.CrossEntropyLoss()


for i in range(10):
    for data,target in loader:
        data = Variable(data)

        target = Variable(target).long()

        output = cnn(data)
        loss = losses(output,target)

        optimizers.zero_grad()
        loss.backward()
        optimizers.step()

        _,pred = torch.max(output,1)
        print(pred)
        if(loss<0.04):
            break
torch.save(cnn.state_dict(),'face.pkl')








