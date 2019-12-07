def stackperm(x,idx=0,stack=None,output=None):
    if stack is None:
        stack = []
    if output is None:
        output= []
    if idx >= len(x):
        yield output+list(reversed(stack))
    elif idx < len(x):
        tmp_stack  = stack.copy()
        tmp_output = output.copy()
        tmp_stack.append(x[idx])
        yield from stackperm(x,idx+1,tmp_stack,tmp_output)
        tmp_stack.pop()
        while len(tmp_stack)>0:
            tmp_output.append(tmp_stack.pop())
            tmp_stack.append(x[idx])
            yield from stackperm(x,idx+1,tmp_stack,tmp_output)
            tmp_stack.pop()      
for idx,p in enumerate(stackperm([0,1,2,3])):
    print(idx,p)
"""
輸出
0 [4, 3, 2, 1]
1 [3, 4, 2, 1]
2 [3, 2, 4, 1]
3 [3, 2, 1, 4]
4 [2, 4, 3, 1]
5 [2, 3, 4, 1]
6 [2, 3, 1, 4]
7 [2, 1, 4, 3]
8 [2, 1, 3, 4]
9 [1, 4, 3, 2]
10 [1, 3, 4, 2]
11 [1, 3, 2, 4]
12 [1, 2, 4, 3]
13 [1, 2, 3, 4]
"""