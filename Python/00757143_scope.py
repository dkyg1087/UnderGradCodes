#1. 答:b會出錯
#因 python 是直譯器，會一行一行讀取。如果先執行函式下面才
# 定義，直譯器會看不道函式的定義而不知道要執行什麼。
def func1(msg):
  return "({})".format(msg)
def func2(msg):
  return "[{}]".format(msg)
def func3(msg):
  return "{}{}{}".format('{',msg,'}')

func1('*')
funcp = func1
funcp('*')

import itertools
for p in itertools.combinations([func1,func2,func3],2):
  print(p[0](p[1]('*')))

