import numpy as np
a = np.array([54, 27, 66, 77, 10,  0, 72, 74, 59])
b = np.array([52, 90, 94, 85, 53, 59, 35, 59, 86])
c = a.reshape(3,3)
print(np.may_share_memory(a,c))#1. view, 因為他們兩個有共用記憶體
z1=np.array([a[:],b[:]]).T#2.
z2=np.array([a[:],b[:]])#3.
print(len(b[b>a]))#4.
w=b[b>a]#5.
w=b[1:-1:]
w=w[[all(t)for t in zip(b[2::]<b[1:-1:],b[1:-1:]>b[:-2:])]]#6.