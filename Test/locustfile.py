x = 0
y = 10
z = 100
try:
    #y/x
    try:
        y / x
    except:
        print("Inner!")
except:
    print("Outer!")