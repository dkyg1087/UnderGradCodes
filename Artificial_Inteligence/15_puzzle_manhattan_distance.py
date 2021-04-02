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

if __name__ == '__main__':
    counter = int(input())
    for _ in range(counter):
        state = input()[0:16]
        print(get_distance(state))