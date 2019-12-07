import os
from os.path import *
dir=input('input the directory:')
for root, dirs, files in os.walk(dir,topdown=True):
    print(root, "has",end=" ")
    print(len(files), "non-directory files and ",end=" ")
    print(sum(os.path.isdir(os.path.join(root, i)) for i in os.listdir(root)),"directory files.",end=" ")
    print(" Consumes",end=" ")
    print(sum(getsize(join(root, name)) for name in files)," bytes.")