import matplotlib.pyplot as plt
import numpy as np
import math
def f(x):
    return 1/(sigma*((2*math.pi)**1/2))*e**((-0.5)*(((x-mu)/sigma)**2))
e=math.exp(1)
mu=0
sigma=1
X=np.linspace(-5,5,100)
F=f(X)
plt.plot(X,F)
plt.show()