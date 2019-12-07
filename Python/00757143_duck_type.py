class two_d:
    def __init__(self,x,y):
        self.x=x
        self.y=y
def distance(p1,p2):
    try:
        dis=((p1.x-p2.x)**2+(p1.y-p2.y)**2)**0.5
    except AttributeError:
        print("Failed!")
        return
    print(dis)
p1=two_d(10,10)
p2=two_d(0,0)
p3=4
distance(p1,p2)
distance(p2,p3)