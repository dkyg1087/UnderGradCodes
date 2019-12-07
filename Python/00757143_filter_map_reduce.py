import math
from functools import reduce
a=[1,-2,3,-4,5,-6,-7,-8,9,10]
#1.使用filter,選擇a裡正的且為3的倍數。
for i in filter(lambda x:x>0 and x%3==0,a):
    print(i)
#2.使用map,將a裡的元素的對映至math.exp(-a)
for i in map(lambda x:math.exp(-i),a):
    print(i)

#3.使用reduce計算a裡的元素絕對值的和
def sum(x,y):
    return abs(x)+abs(y)
print(reduce(sum,a))