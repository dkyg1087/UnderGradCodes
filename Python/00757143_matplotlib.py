import matplotlib.pyplot as plt
import numpy as np
from matplotlib.font_manager import FontProperties
import os
font = FontProperties(fname=os.environ['WINDIR']+'\\Fonts\\kaiu.ttf', size=16)
data2=np.array([['高','低','中','低','中'],['低','中','高','高','中'],['高','中','中','低','中']])
data2_mod=np.where(data2=='高',2,np.where(data2=='中',1,0))
label=np.array(['甲公司','乙公司','丙公司'])
plt.figure(figsize=(4,5))
for i in range(3):
    plt.plot(np.arange(data2_mod.shape[1]),data2_mod[i,:],label=label[i])
plt.yticks(np.arange(label.shape[0]),['低','中','高'],fontproperties=font)
plt.xticks(np.arange(data2_mod.shape[1]),['103','104','105','106','107'],fontproperties=font)
plt.legend(loc='best',prop=font)
plt.title("103年~107年各公司業績",fontproperties=font)
plt.xlabel('年',fontproperties=font)
plt.ylabel('業績高低',fontproperties=font)
plt.show()