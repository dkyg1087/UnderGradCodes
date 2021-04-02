import copy
def swap(state,i,j,ii,jj):
    dpcp = copy.deepcopy(state)
    dpcp[i][j],dpcp[ii][jj]=dpcp[ii][jj],dpcp[i][j]
    res = "".join(cha for row in dpcp for cha in row)
    return res
def show_successor(state):
    successor = []
    current = []
    idx = 0
    for _ in range(4):
        current.append(copy.copy([i for i in state[idx:idx+4]]))
        idx = idx + 4
    loc_i = 0
    loc_j = 0
    for i in range(4):
        for j in range(4):
            if current[i][j] == '0':
                loc_i=i
                loc_j=j
                break
    if loc_i > 0:
        successor.append(("up",swap(current,loc_i,loc_j,loc_i-1,loc_j)))
    if loc_i < 3 :
        successor.append(("down",swap(current,loc_i,loc_j,loc_i+1,loc_j)))
    if loc_j > 0 :
        successor.append(("left",swap(current,loc_i,loc_j,loc_i,loc_j-1)))
    if loc_j < 3 :
        successor.append(("right",swap(current,loc_i,loc_j,loc_i,loc_j+1)))
    return successor

if __name__ == '__main__':
    counter = int(input())
    for _ in range(counter):
        state = input()[0:16]
        show_successor(state)
        ans = show_successor(state)
        print(len(ans))
        for i in ans:
            print("move 0 to "+i[0]+"\n"+i[1])