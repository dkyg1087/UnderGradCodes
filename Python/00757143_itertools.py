import itertools
ans=[]
for x in range(1,100) :
    for y in range(1,x) :
        for z in range(1,y) :
            if x**2==y**2+z**2 :
              if x+y+z<100:
                ans.append([z,y,x])
print(ans)
lis=['A','B','C','D','E','F']
dic={}
for i in range(1,len(lis)):
  for key in itertools.combinations(lis,i):
    dic[key]=0
print(dic)
"""
輸出:
[[3, 4, 5], [6, 8, 10], [5, 12, 13], [9, 12, 15], [8, 15, 17],
[12, 16, 20], [15, 20, 25], [7, 24, 25], [10, 24, 26], [20, 21, 29], 
[18, 24, 30], [16, 30, 34], [21, 28, 35], [12, 35, 37],
[15, 36, 39], [24, 32, 40], [9, 40, 41]]
{('A',): 0, ('B',): 0, ('C',): 0, ('D',): 0, ('E',): 0, 
('F',): 0, ('A', 'B'): 0, ('A', 'C'): 0, ('A', 'D'): 0, 
('A', 'E'): 0, ('A', 'F'): 0, ('B', 'C'): 0, ('B', 'D'): 0, 
('B', 'E'): 0, ('B', 'F'): 0, ('C', 'D'): 0, ('C', 'E'): 0, 
('C', 'F'): 0, ('D', 'E'): 0, ('D', 'F'): 0, ('E', 'F'): 0, 
('A', 'B', 'C'): 0, ('A', 'B', 'D'): 0, ('A', 'B', 'E'): 0, 
('A', 'B', 'F'): 0, ('A', 'C', 'D'): 0, ('A', 'C', 'E'): 0, 
('A', 'C', 'F'): 0, ('A', 'D', 'E'): 0, ('A', 'D', 'F'): 0, 
('A', 'E', 'F'): 0, ('B', 'C', 'D'): 0, ('B', 'C', 'E'): 0, 
('B', 'C', 'F'): 0, ('B', 'D', 'E'): 0, ('B', 'D', 'F'): 0, 
('B', 'E', 'F'): 0, ('C', 'D', 'E'): 0, ('C', 'D', 'F'): 0, 
('C', 'E', 'F'): 0, ('D', 'E', 'F'): 0, ('A', 'B', 'C', 'D'): 0, 
('A', 'B', 'C', 'E'): 0, ('A', 'B', 'C', 'F'): 0, ('A', 'B', 'D', 'E'): 0, 
('A', 'B', 'D', 'F'): 0, ('A', 'B', 'E', 'F'): 0, ('A', 'C', 'D', 'E'): 0, 
('A', 'C', 'D', 'F'): 0, ('A', 'C', 'E', 'F'): 0, ('A', 'D', 'E', 'F'): 0, 
('B', 'C', 'D', 'E'): 0, ('B', 'C', 'D', 'F'): 0, ('B', 'C', 'E', 'F'): 0, 
('B', 'D', 'E', 'F'): 0, ('C', 'D', 'E', 'F'): 0, ('A', 'B', 'C', 'D', 'E'): 0, 
('A', 'B', 'C', 'D', 'F'): 0, ('A', 'B', 'C', 'E', 'F'): 0, ('A', 'B', 'D', 'E', 'F'): 0, 
('A', 'C', 'D', 'E', 'F'): 0, ('B', 'C', 'D', 'E', 'F'): 0}
"""