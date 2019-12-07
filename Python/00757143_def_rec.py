class Rectangle:
    def __init__(self,x,y,width,height):
        self.x0=x
        self.y0=y
        self.width=width
        self.height=height
    def __str__(self):
        return "Rectangle: ("+str(self.x0)+","+str(self.y0)+")-("+str(self.x0+self.width)+","+str(self.y0+self.height)+")"
    def __repr__(self):
        return "Rectangle ({},{},{},{})".format(self.x0,self.y0,self.width,self.height)
    def __eq__(self,other):
        return self.height==other.height and self.width==other.width and self.x0==other.x0 and self.y0==other.y0
    def __or__(self,other):
        if self.x0>other.x0:
            x=other.x0
        else:
            x=self.x0
        if self.y0>other.y0:
            y=other.y0
        else:
            y=self.y0
        if (self.x0+self.height)>(other.x0+other.height):
            height=self.x0+self.height-x
        else :
            height=other.x0+other.height-x
        if (self.y0+self.width)>(other.y0+other.width):
            width=self.y0+self.width-y
        else:
            width=other.y0+other.width-y
        return Rectangle(x,y,width,height)
    def __and__(self,other):
        if(self.x0<other.x0):
            x=other.x0
        else :
            x=self.x0
        if(self.y0<other.y0):
            y=other.y0
        else:
            y=self.y0
        if (self.x0+self.height)<(other.x0+other.height):
            height=self.x0+self.height-x
        else :
            height=other.x0+other.height-x
        if (self.y0+self.width)<(other.y0+other.width):
            width=self.y0+self.width-y
        else:
            width=other.y0+other.width-y
        if(height<0 or width<0):
            return "No such thing as'{}&{}'.".format(self,other)
        else:
            return Rectangle(x,y,width,height)
    @property
    def area(self):
        return self.width*self.height
rect=Rectangle(0,0,5,4)
print(rect)#1.
print(rect.area)#2.
rect2=Rectangle(1,1,5,4)
rect3=Rectangle(6,6,1,1)
print(rect|rect2)#3.
print(rect&rect2)
print(rect&rect3)#4.
#5. is everywhere
print(rect == eval(repr(rect)))#6.
"""
輸出
Rectangle: (0,0)-(5,4)
20
Rectangle: (0,0)-(6,5)
Rectangle: (1,1)-(5,4)
No such thing as'Rectangle: (0,0)-(5,4)&Rectangle: (6,6)-(7,7)'.
True
"""


       