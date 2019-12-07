import numpy as np
class myChain:
    def __init__(self,*therest):
        self.tup=np.array(list(therest))
    def __iter__(self):
        f1=self.tup.flat
        return f1
x=myChain([1,2,3],[4,5,6],[1,5,6])
for i in x:
    print(i,end=" ")
"""
輸出
1 2 3 4 5 6 1 5 6
"""