import numpy as np
def create_mdl(tp,default=None):
    a=()
    a = np.zeros(tp, dtype=np.int64)
    for i in np.nditer(a,op_flags=['readwrite']):
        i[...]=default
    return a
a=create_mdl((3,3,3),100)
print(a)
"""
輸出:
[[[100 100 100]
  [100 100 100]
  [100 100 100]]

 [[100 100 100]
  [100 100 100]
  [100 100 100]]

 [[100 100 100]
  [100 100 100]
  [100 100 100]]]
"""