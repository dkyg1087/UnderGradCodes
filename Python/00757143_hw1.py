print('第一筆運算')
m=int(input('第一個數字:'))
n=int(input('第二個數字:'))
a=m-n
sum=1
for i in range(1,m+1):
  sum*=i
m=sum
sum=1
for i in range(1,n+1):
  sum*=i
n=sum
sum=1
for i in range(1,a+1):
  sum*=i
a=sum
ans=(m/n)/a
print('答案',ans)
print('第二筆運算')
m=int(input('第一個數字:'))
n=int(input('第二個數字:'))
a=m-n
sum=1
for i in range(1,m+1):
  sum*=i
m=sum
sum=1
for i in range(1,n+1):
  sum*=i
n=sum
sum=1
for i in range(1,a+1):
  sum*=i
a=sum
ans=(m/n)/a
print('答案',ans)
"""
輸入
--------------------
100
50
200
100



執行結果
--------------------
第一筆運算
第一個數字:100
第二個數字:50
答案 1.008913445455642e+29
第二筆運算
第一個數字:200
第二個數字:100
答案 9.054851465610328e+58
"""