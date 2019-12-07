import threading
 
def my_proc(data,lock):
    for _ in range(100000):
        with lock:
            for i in range(len(data)):
                data[i] = data[i] + 1

data = [1,2,3,4]
lock_object=threading.Lock()
thread1 = threading.Thread(target=my_proc,args=(data,lock_object))
thread2 = threading.Thread(target=my_proc,args=(data,lock_object))

thread1.start()
thread2.start()

thread1.join()
thread2.join()

print(data)
"""
輸出:[200001, 200002, 200003, 200004]
"""