import sys
even,odd=0,0
for line in sys.stdin :
    num=int(line)
    if num%2==0 :
        even+=num
    else:
        odd+=num
print('odd:{} even:{}'.format(odd,even))
"""
輸入
-----------------------------------------
1
3
5
7
9
2
4
6
8
10
^Z

輸出
-------------------------------------
odd:25 even:30
"""