import threading
from datetime import *
import time
import sys
import asyncio
def foo(event):
    while not event.is_set():
            print("{} alive".format(datetime.now().strftime("%H:%M:%S")))
            time.sleep(5)
try:
    event=threading.Event()
    thread=threading.Thread(target=foo,args=(event,))
    thread.start()
    event.wait()
except KeyboardInterrupt:
    print(" Interrupted.")
    event.set()
    sys.exit(1)
"""
理論上上面的code好像要吃的到interupt可是我的不會QQ
不理終止條件的code:
import threading
from datetime import *
import time

def foo():
    while True:
        print("{} alive".format(datetime.now().strftime("%H:%M:%S")))
        time.sleep(5)
thread=threading.Thread(target=foo)
thread.start()
thread.join()
"""