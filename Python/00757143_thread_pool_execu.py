import threading
import zipfile
import re
import multiprocessing
import numpy
from concurrent.futures import as_completed,ProcessPoolExecutor,ThreadPoolExecutor
def read_data(filename):
    total = 0
    with zipfile.ZipFile(filename) as zipfp:
        with zipfp.open(zipfp.namelist()[0],'r') as fp:
            for a_line in fp.readlines():
                a_line = a_line.decode('utf-8')
                for number in re.finditer(r'(\d+(\.?\d*)|\.\d+)',a_line):
                    total += float(number.group())
    return total
result=[]
for workers in range(1,6):
    with ThreadPoolExecutor(max_workers=5) as executor:
        futures=[executor.submit(read_data,"ex2_"+str(i)+".zip")for i in range(1,6)]
        for future in as_completed(futures):
            result.append(future.result())
print(numpy.mean(result))
