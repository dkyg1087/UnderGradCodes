#this code is to check the solvability  of a state of 15 puzzle

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

if __name__ == '__main__':
    counter = int(input())
    for _ in range(counter):
        state = input()[0:16]
        if is_solvable(state):
            print('YES')
        else:
            print('NO') 
    