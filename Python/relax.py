"""
sum=0
for i in range(1,6):
    x=int(input("Please input the number of bugs caught in day "+str(i)+":"))
    sum+=x 
print("The total number of bugs:",sum)



x=int(input("Please enter a non-negative number to be calculated:"))
fac=1
for i in range(1,x+1):
    fac*=i
print("factorial of",x,"is",fac)



def max(x,y):
    if x>y:
        return x
    else:
        return y
x=int(input("Enter the first number:"))
y=int(input("Enter the second number:"))
print("The bigger one is:",max(x,y))



def is_prime(x):
    if x==1:
        return False
    for i in range(2,int(x**0.5)+1) :
        if x%i==0:
            return False
    return True
x=int(input("Enter a number to be checked:"))
if is_prime(x):
    print(x,"is a prime.")
else:
    print(x,"isn't a prime.")

def repeat(str,x):
    for i in range(1,x+1):
        print(str,end="")
    return

-----------------------------

from statistics import mean
lst=[]
with open("number.txt","r") as fp:
    data=fp.readlines()
    for dt in data:
        lst.extend(dt.split())
    lst = [int(x) for x in lst]
    print(mean(lst))

from numpy import random
lst=[]
for _ in range(1,8):
    lst.append(random.randint(0,10))
for num in lst:
    print(num,end=" ")

glst=[]
blst=[]
with open("GirlNames.txt","r") as gfp,open("BoyNames.txt","r") as bfp:
    data1=gfp.readlines()
    data2=bfp.readlines()
    for dtg,dtb in zip(data1,data2):
        glst.extend(dtg.split())
        blst.extend(dtb.split())
    while(True):
        targ=input("Please enter names to search(type 'Quit' to quit):")
        if targ=="Quit" or targ=="quit":
            break
        targ=targ.split()
        for names in targ:
            if names in glst:
                print(names,"is among the most popular Girls.")
            elif names in blst:
                print(names,"is among the most popular Boys.")
            else:
                print(names,"is neither in the Boys nor the Girls list.")
"""
import matplotlib.pyplot as plt
with open("1994_Weekly_Gas_Avgerages.txt","r")as fp:
    plt.style.use('ggplot')
    x=fp.readlines()
    x=[int(x) for x in x]
    weeks=[]
    for i in range(1,11):
        weeks.append("week "+str(i))
    x_pos=[i for i,_ in enumerate(weeks)]
    plt.bar(x_pos,x, color='green')
    plt.xlabel("Weeks")
    plt.ylabel("Price")
    plt.title("1944 Weekly Gas Avgs")
    plt.xticks(x_pos, weeks)
    plt.show()
