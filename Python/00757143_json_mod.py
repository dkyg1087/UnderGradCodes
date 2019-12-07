import json
import numpy as np
class Point:
    def __init__(self,x,y):
        self.x=x
        self.y=y
    def __iter__(self):
        return iter([self.x,self.y])
    
pt = [Point(np.random.randint(0,1000)-500,np.random.randint(0,1000)-500) for _ in range(100)]
#1.
def convert(obj):
    return {'x':obj.x,'y':obj.y}
with open('points.txt','w')as fp:
    json.dump(pt,fp,default=convert,separators=(',',':'))
#2.
def custom_obj(obj):
    return Point(obj['x'],obj['y'])
with open('points.txt','r') as fp:
    data=json.load(fp,object_hook=custom_obj)
    for p in data:
        print('x:{} y:{}'.format(p.x,p.y))
