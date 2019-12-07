import numpy as np
A=np.ndarray((200,200),dtype=np.float)#1.
A[100,:]=100#2.
A[:,1::2]=500#3.
B=A[:].copy()#4.