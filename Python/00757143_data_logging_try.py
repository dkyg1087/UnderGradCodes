import logging
logging.basicConfig(filename='read.log', level=logging.INFO)
try:
    LineCount = 1
    with open('ch6ex1.txt','r') as fp:
        for line in fp:
            print("-"*10)
            print("Original DATA: ",line , end='')
            line = line.strip('\n') 
            data = line.split(',')
            print("NO." , LineCount, "({})".format(len(data)) , data)
            print()
            LineCount += 1 
            try:
                if len(data) != 4:
                    raise ValueError
            except ValueError:
                logging.exception("Line #{}: Input Data Field Not Match".format(LineCount))
                print("Data Field error: Too Many or too less")
                continue
            try:
                int(data[1])
                int(data[2])
            except ValueError:
                logging.exception("Line #{}: Data Type Error: \"{}\" is not a number".format(LineCount,data[1]))
                print("Data format NOT MATCH: Not a Number")
                continue
            try:
                temp = int(data[3])
                if temp != 0 and temp != 1:
                    raise ValueError
            except ValueError:
                logging.exception("Line #{}:Data Value Error: Not 0 or 1".format(LineCount))
                print("NOT 0 or 1")
                continue
except FileNotFoundError as err:
        print("File not Found.")
        logging.exception(err)
logging.shutdown()
