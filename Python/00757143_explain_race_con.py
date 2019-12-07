import threading
 
def my_proc(data):
    for _ in range(100000):
        for i in range(len(data)):
          data[i] = data[i] + 1

data = [1,2,3,4]
thread1 = threading.Thread(target=my_proc,args=(data,))
thread2 = threading.Thread(target=my_proc,args=(data,))

thread1.start()
thread2.start()

thread1.join()
thread2.join()

print(data)
"""
輸出:[171820, 181038, 186008, 174496]

因為Race condition,在第一個thread做完+1之前thread2就已經和同樣的data做請求並複製值
假設程序中有一個data值是10:

time ----->

thread1:  10 -----> 10+1=11 ----->    11
        (讀取)                         |
thread2:  |      10 -----> 10+1=11     |    ----->   11 
          |     (讀取)               (寫入)          (寫入)
data:     10     10                  10->11         11->11

理論上應算出12  可是實際上跑完的程序是11
"""