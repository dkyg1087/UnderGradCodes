import numpy as np
A=np.array([
        [4,3,2],
        [-2,4,-3],
        [1,-1,1]
            ])
B=np.array([9,8,7]).reshape(3,1)
A_inv=np.linalg.inv(A)
ans=A_inv.dot(B)
print("x={},y={},z={}".format(ans[0],ans[1],ans[2]))
"""
輸出
-----------------------
x=[50.],y=[-21.],z=[-64.]
"""