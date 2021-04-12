import copy
import heapq

def get_coord(num):
    i=num//4
    j=num%4
    return i,j 

def get_distance(state):
    distance = 0
    for k in range(1,len(state)):
        i,j=get_coord(k)
        ii=jj=0
        for idx in range(len(state)):
            if int(state[idx],16) == k:
                ii,jj = get_coord(idx)
                break
        distance += (abs(i-ii)+abs(j-jj))
    return distance

def is_solvable(state):
    z_pos = state.find('0')
    count = z_pos//4 
    for i in range(len(state)):
        j=i+1
        while j<len(state):
            if int(state[i],16) > int(state[j],16) and state[i] != '0' and state[j] != '0':
                count = count + 1
            j = j+1
    if count % 2 == 0:
        return True
    else:
        return False

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

class puzzleState(object):
    def __init__(self,cost,distance,state,order,parent,direction):
        self.cost = cost
        self.distance = distance
        self.state = state
        self.order = order
        self.parent = parent
        self.direction = direction
    def __repr__(self):
        return self.state
    def __lt__(self,other):
        if (self.cost + self.distance) == (other.cost + other.distance):
            return self.order < other.order
        else:
            return (self.cost + self.distance) < (other.cost + other.distance)

if __name__ == '__main__':
    state = input()[0:16]
    if state == '0123456789ABCDEF':
        print('It is the goal state.')
    elif not is_solvable(state):
        print('No solution!!')
    else:
        order = 0
        current = puzzleState(0,get_distance(state),state,order,None,None)
        end = None
        state_queue=[]
        heapq.heappush(state_queue,current)
        while state_queue:
            state = heapq.heappop(state_queue)
            if state.state == '0123456789ABCDEF':
                end = state
                break
            successor = show_successor(state.state)
            for pth in successor:
                order = order+1
                node = puzzleState(state.cost+1,get_distance(pth[1]),pth[1],order,state,pth[0])
                heapq.heappush(state_queue,node)
        if end == None:
            print('No solution!!')
        else:
            step = []
            i = end
            while i.parent != None:
                step.append(i.direction)
                i = i.parent
            step.reverse()
            for stp in step:
                print("move 0 to "+stp)