"""
   作者:吴恢鹏
   时间：2019年2月13日20:33:40
   功能：example数据整理
"""

import pymysql
import re
import json



def get_index_info():
    sql = "SELECT INDEX_INFO FROM journal_info"
    cursor.execute(sql)
    one = cursor.fetchall()
    for i in one:
        if i[0]:
            q = i[0].split('|')
            print(q)

def get_json_basic_info():
    sql = "SELECT BASIC_INFO  FROM journal_info"
    cursor.execute(sql)
    one = cursor.fetchall()
    for n in one:
        m = (re.sub(' ','',(''.join(n[0].split('\n')))))
        time = '---'
        post = '---'
        outs = '---'
        if re.findall('创刊时间：(.*)',m):
            time = re.findall('创刊时间：(.*)',m)[0]
        if re.findall('邮发代号：(.*?)创刊时间',m):
            post = re.findall('邮发代号：(.*?)创刊时间',m)[0]
        if re.findall('开本：(.*?)邮发',m):
            out = re.findall('开本：(.*?)邮发',m)[0]

        yield {
        '主办单位':re.findall('主办单位：(.*?)出',m)[0],
        '出版周期':re.findall('出版周期：(.*?)I',m)[0],
        'ISSN'   :re.findall('ISSN：(.*)C',m)[0],
        'CN'     :re.findall('CN：(.*?)出',m)[0],
        '出版地'  :re.findall('出版地：(.*?)语种',m)[0],
        '语种'    :re.findall('语种：(.*?)开本',m)[0],
        '开本'    :outs,
        '邮发代号' :post,
        '创刊时间' :time,


    }

def get_json_publish_info():
    sql = 'SELECT publish_info FROM journal_info'
    cursor.execute(sql)
    one = cursor.fetchall()
    for i in one:
        n = re.sub(' ','',(''.join(i[0].split('\n'))))

        yield {
            '专辑名称'  :re.findall('专辑名称：(.*?)专题',n)[0],
            '专题名称'  :re.findall('专题名称：(.*?)出版',n)[0],
            '出版文献量':re.findall('出版文献量：(.*?)总下载',n)[0],
            '总下载次数':re.findall('总下载次数：(.*?)总被引次数',n)[0],
            '总被引次数':re.findall('总被引次数：(.*)',n)[0]
        }

def get_json_evaluate_info():
    sql = 'SELECT evaluate_info from journal_info'
    cursor.execute(sql)
    one = cursor.fetchall()
    for i in one:
        n = re.sub(' ','',(''.join(i[0].split('\n'))))

        glory = '无'
        source = '未知'
        composite = '无'
        data = '未知'
        if re.findall('期刊荣誉：(.*?)',n) and re.findall('期刊荣誉：(.*?)',n)[0]!='':
            glory = re.findall('期刊荣誉：(.*?)',n)[0]
        if re.findall('来源期刊：(.*?)期刊荣誉',n):
            source = re.findall('来源期刊：(.*?)期刊荣誉',n)[0]
        if re.findall('（2018版）综合影响因子：(.*?)该',n):
            composite = re.findall('（2018版）综合影响因子：(.*?)该',n)[0]
        if re.findall('该刊被以下数据库收录：(.*?)来源期刊',n):
            data = re.findall('该刊被以下数据库收录：(.*?)来源期刊',n)[0]
        yield {
            '（2018版）复合影响因子':re.findall('（2018版）复合影响因子：(.*?)（2018版）',n)[0],
            '（2018版）综合影响因子':composite,
            '该刊被以下数据库收录'   :data,
            '来源期刊'             :source,
            '期刊荣誉'             :glory
        }

def up_basic(basic):
    x = 1
    for i in basic:
        # json.dumps(i,ensure_ascii=False) 变成json格式
     sql = 'UPDATE journal_info SET basic_info="%s" WHERE id= %s'%(i,x)

     cursor.execute(sql)
     db.commit()
     x += 1

def up_publish(publish):
    x = 1
    for i in publish:
        sql = 'UPDATE journal_info SET publish_info="%s" WHERE id= %s' % (i,x)

        cursor.execute(sql)
        db.commit()
        x += 1

def up_evaluate(evaluate):
    x = 1
    for i in evaluate:
        sql = 'UPDATE journal_info SET evaluate_info="%s" WHERE id= %s' % (i,x)

        cursor.execute(sql)
        db.commit()
        x += 1



db = pymysql.connect(host='localhost', user='root', password='wuhuipeng', port=3306, db='example')

cursor = db.cursor()

get_index_info() #打印index_info字段

basic = get_json_basic_info() #整理basic_info字段

publish = get_json_publish_info() #整理publish_info字段

evaluate = get_json_evaluate_info() #整理evaluate_info字段

up_basic(basic) #更新basic_info字段

up_publish(publish) #更新publish_info字段

up_evaluate(evaluate) #更新evaluate_info字段
