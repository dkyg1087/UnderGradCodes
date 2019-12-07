alist=[1,2,-1,2,-3,5,6,-4]
for i in alist:
    print(i)#1.列出list alist裡的元素
for i,j in enumerate(alist):
    print(i,j)#2.列出list alist裡的元素值及足標
for u in set(alist):
    if(u<0):
        alist.remove(u)
print(alist)#3.刪除list alist裡的小於0的元素
alist=[1,2,3,4]
blist=[6,7,8,9]
clist=[11,2,3,1]
for a,b,c in zip(alist,blist,clist):
    print(a,b,c)#4.同時疊代lists alist,blist,clist裡的元素:
import itertools
for c in itertools.cycle(['Sun','Mon','Tue','Wed','Thu','Fri','Sat']):
    print(c)#5.重複反覆輸出Sun, Mon,Tue, Wed, Thu, Fri, Sat:

