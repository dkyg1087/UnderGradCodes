import datetime
#第一題
t1=input("input the first date:")
t2=input("input the second date:")
t1=datetime.datetime.strptime(t1,"%Y-%m-%d %H:%M:%S")
t2=datetime.datetime.strptime(t2,"%Y-%m-%d %H:%M:%S")
print('相差',abs((t2-t1).days),"天")
print('相差',abs((t2-t1).total_seconds()),"秒")
#第二題
n=input("input your days:")
print(str(datetime.date.today()+datetime.timedelta(days=int(n))),"跟現在相差",n,"天")
"""
輸入
2017-11-18 17:05:31
2013-11-18 17:05:31
10
輸出
input the first date:2017-11-18 17:05:31
input the second date:2013-11-18 17:05:31
相差 1461 天
相差 126230400.0 秒
input your days:10
2019-10-31 跟現在相差 10 天
"""