import time
def f1(n=1000000):
    a=time.time()
    s = 0
    for i in range(n):
        s += i
    b=time.time()
    return print('處理程序耗時: {} 秒'.format(b-a))

def f2(n=1000000):
    a=time.time()
    s = 0
    lst = list(range(n))
    for i in lst:
        s += i
    b=time.time()
    return print('處理程序耗時: {} 秒'.format(b-a))
f1()
f2()