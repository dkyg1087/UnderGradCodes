import numpy as np
np.random.seed(100)
X = np.random.rand(1000,10)
n2=np.sum(X*X,axis=1)
D=n2.reshape((1,-1))+n2.reshape((-1,1))-2*np.dot(X,X.T)#1.
print(int(len(D[D<2])/2))#2.
#3.  不會QQ
#4.  不會QQ
