import matplotlib.pyplot as plt
import numpy as np
import math
from scipy import integrate
from collections import Counter
"""
def normal(x):
    return 1/(sigma*((2*math.pi)**1/2))*e**((-0.5)*(((x-mu)/(sigma**2))**2))
e=math.exp(1)
X=np.linspace(-5,5,100)
lst=[[[0,1],[0,1]],[[1,1],[-1,1]],[[0,1],[0,1.3]],[[-2,1],[0,1.3]]]
plt.style.use('ggplot')
x=1
plt.figure(figsize=(25,25))
for data in lst:
    plt.subplot(4,3,x)
    for stuff in data:
        mu=stuff[0]
        sigma=stuff[1]
        plt.plot(X,normal(X))
    x=x+1
def gama(x):
    return (1/((beta**alpha)*math.factorial(alpha-1)))*(x**(alpha-1))*e**(-1*x/beta)
lst2=[[[1,1],[2,1],[4,1]],[[1,2],[1,1],[1,0.67]]]
Y=np.linspace(0,10,100)
for data in lst2:
    plt.subplot(4,3,x)
    for stuff in data:
        alpha=stuff[0]
        beta=stuff[1]
        plt.plot(Y,gama(Y))
    x=x+1
def chi_square(x):
    aaa= lambda x,a: x**(a-1)*math.exp(-1*x)
    re,err=integrate.quad(aaa,0,np.inf,args=(alpha,))
    return (1/((beta**alpha)*re))*(x**(alpha-1))*e**(-1*x/beta)
plt.subplot(4,3,x)
lst3=[[0.5,2],[1,2],[1.5,2],[2,2],[3,2],[4.5,2]]
for stuff in lst3:
        alpha=stuff[0]
        beta=stuff[1]
        plt.plot(Y,chi_square(Y))
x=x+1
plt.ylim(0,0.5)
plt.xlim(0,8)
"""
def normal(x):
    return 1/(sigma*((2*math.pi)**1/2))*e**((-0.5)*(((x-mu)/(sigma**2))**2))
mother=np.random.randint(1,100,1000)
#plt.subplot(5,3,x)
sample=[]
mu=mother.mean()
sigma=(np.var(mother)**1/2)/50**(1/2)
for _ in range(100):
    sample.append(int(np.random.choice(mother,500).mean()))
counter=Counter(sample)
#for i in set(sample):
    #plt.bar(i,counter[i])
#plt.subplot(5,3,x+3)
sample=np.array(sample)
sample.sort( )
plt.plot(sample,normal(sample))
plt.xlim(0,100)
plt.show()