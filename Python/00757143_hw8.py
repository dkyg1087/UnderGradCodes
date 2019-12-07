s={} #設定s為空集合。
print(s)
s={1,2,3} #設定s為集合{1,2,3}。
print(s)
s.add(5) #加入5至集合s。
print(s)
s.remove(1) #將1從s刪除。
print(s)
s=[1,2,3,4] #設定s為list [1,2,3,4]。
print(s)
s.extend([5,6,7]) #將[5,6,7]三個元素加入s。
print(s)
s.append([5,6,7]) #將[5,6,7]整個list(當做一個元素)加入s。
print(s)
t=s.copy()#將s複製給t (copy)。
print(t)
s.remove([5,6,7])#不然不能sort
s.sort(reverse=True)#排序
print(max(s))#最大
print(min(s))#最小
print(s.count(2))#有幾個2
print(sum(s))#總和
x={"a":1,"b":2,"c":3}#建立key='a','b','c',value=1,2,3的dict x。
print(x)
del x["a"]#由x刪除key=a的元素。
print(x)

"""
輸出
-----------------------
{}
{1, 2, 3}
{1, 2, 3, 5}
{2, 3, 5}
[1, 2, 3, 4]
[1, 2, 3, 4, 5, 6, 7]
[1, 2, 3, 4, 5, 6, 7, [5, 6, 7]]
[1, 2, 3, 4, 5, 6, 7, [5, 6, 7]]
7
1
1
28
{'a': 1, 'b': 2, 'c': 3}
{'b': 2, 'c': 3}
"""
