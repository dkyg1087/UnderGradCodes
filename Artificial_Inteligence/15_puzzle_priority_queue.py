import heapq

class puzzleState(object):
    def __init__(self,cost,distance,state,order):
        self.cost = cost
        self.distance = distance
        self.state = state
        self.order = order
    def __repr__(self):
        return self.state
    def __lt__(self,other):
        if (self.cost + self.distance) == (other.cost + other.distance):
            return self.order < other.order
        else:
            return (self.cost + self.distance) < (other.cost + other.distance)

if __name__ == '__main__':
    counter = int(input())
    priorityq = []
    order = 0
    for _ in range(counter):
        cmd = input()
        cmd = cmd.replace('\r','')
        if cmd == 'enqueue':
            inpt = input()
            inpt = inpt.replace('\r','')
            obj = inpt.split(" ")
            heapq.heappush(priorityq,puzzleState(int(obj[1]),int(obj[2]),obj[0],order))
            order = order + 1
            print("Insert OK!")
        else:
            if priorityq:   
                state = heapq.heappop(priorityq)
                print("Got "+str(state))
            else:
                print("Queue is empty!!")