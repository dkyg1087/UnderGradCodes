import csv
import numpy as np
class Point:
    def __init__(self,x,y):
        self.x=x
        self.y=y
    def __iter__(self):
        return iter([self.x,self.y])
    
pt = [Point(np.random.randint(0,1000)-500,np.random.randint(0,1000)-500) for _ in range(100)]
#1.
point=[]
for pt_i in pt:
    point.append({'x':pt_i.x,'y':pt_i.y})
with open('points.csv','a+',encoding='Big5',newline='') as csvfile:
    fieldnames=['x','y']
    writer=csv.DictWriter(csvfile, fieldnames=fieldnames, quotechar="'")
    writer.writeheader()
    writer.writerows(point)
#2.
with open('points.csv','r',encoding="Big5",newline='') as csvfile:
    reader=csv.DictReader(csvfile,delimiter=',',quotechar="'")
    for p in reader:
        p=Point(p['x'],p['y'])
        print('x:{} y:{}'.format(p.x,p.y))