import decimal
m=decimal.Decimal(input('本金:'))
r=decimal.Decimal(input('利息:'))
y=decimal.Decimal(input('幾年:'))
ans=m*(1+r)**y
print('本利和:',ans)
""""
輸入
------------------------
40000
0.07
20


執行結果
------------------------
本金:40000
利息:0.07
幾年:20
本利和: 154787.3784994471633294616126
"""
