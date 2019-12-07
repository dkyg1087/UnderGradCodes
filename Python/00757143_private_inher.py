class A:
  def __init__(self):
    print('A__init__')
    self.__x = 1
    self.y   = 1
  def f(self):
    print('A',self.__x,self.y)

class B:
  def __init__(self):
    print('B__init__')
    self.__x = 2
    self.y   = 2
  def f(self):
    print('B',self.__x,self.y)

class C(A,B):
  def __init__(self):
      print('C__init__')
      self.__x = 3
      self.y   = 3 
      super(C,self).__init__()
      super(A,self).__init__()
  def f(self):
      print('C',self.__x,self.y)
c=C()
print('-----------')
c.f()
print('-----------')
super(C,c).f()
print('-----------')
super(A,c).f()
print('-----------')
c.y=9
c.f()
print('-----------')
"""
1.  C__init__
    A__init__
    B__init__
2.  C 3 2
3.  A 1 2 執行到A類別的f 看的是C裡面 A的隱藏 x 跟 C的 y
4.  B 2 2 執行到B類別的f 看的是C裡面 B的隱藏 x 跟 C的 y
5.  C 3 9 self.__x 因為都是private所以各自是各自的變數，
                   但是self.y是public所以每一次的呼叫都會更動y的值，
                   而最後一次更改是呼叫B的y 所以才會是2 
"""