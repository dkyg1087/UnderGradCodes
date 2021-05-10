def cut_rop( n , p) :  
  a= []  
  a.append(0)  
  a.append(p[1])   
  for j in range(2,n+1):  
    ans = -100000  
    for i in range(1,j+1):  
      if j-i > len(p)-1 or i>len(p)-1:  
        ans = ans  
      else :  
        ans = max(ans , p[i]+a[j-i])  
    a.append(ans)
    if j%5000 == 0:
        print(j,"still here")
  print(a[n],end = '\n')
File=open('test-104849.in',"r")
length = int(File.readline())  
plist = [] ;plist.append(0)  
while True:
    nap = File.readline().split()
    #nap = input().split()  
    if int(nap[0]) == 0 and int(nap[1]) == 0 :  
        break  
    else :  
      plist.append(int(nap[1]))
cut_rop(length , plist)
File.close()