import threading
from bs4 import BeautifulSoup
import requests
from collections import Counter
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties
import os
font = FontProperties(fname=os.environ['WINDIR']+'\\Fonts\\kaiu.ttf', size=5)
def do_stuff(item_data,cmd):
    d=[]
    targ=[]
    for s in item_data:
        d.extend(s)
    for stuff in d:
        if type(stuff)==list:
            targ.extend(stuff)
        else:
            targ.append(stuff)
    for i,item in enumerate(targ):
        if item in ['蛋糕','餅乾','零食','茶葉蛋','口香糖','食品 ','晚餐','糖果','吐司','煎餃','爆米花','餐點','泡麵','麵包','玉米湯','健康食品','餐飲','便當','午餐','霜淇淋','布丁','早餐','優格','麵','餐飲費','餐費','食品','餐飲費 ','湯圓','燴飯','用品食品','食品份','熱湯','火鍋','飯糰','滷味','雞蛋','用餐','薯條雞塊']:
            targ[i]="食品"
        elif item in ['鮮乳','綠茶','鮮奶','豆漿','酒類','乳品','飲品杯','飲料','咖啡','礦泉水','礦泉水','咖啡','水','乳品','優酪乳','飲品券','食品飲料','啤酒','食品飲品菸品','飲品','飲品罐','酒品罐','飲料零食','飲品 ','菸品飲料','酒品']:
            targ[i]="飲品"
        elif item in ['汽油','九五無鉛汽油','柴油','液化石油氣']:
            targ[i]="油品"
        elif item in ['文具用品','文具','童書','圖書','紙張用品']:
            targ[i]="文書"
        elif item in ['收視費','連線費','市話寬頻業務 ','代收小額付費','電信服務費','電信服務','電信','電信費','市話寬頻業務','市話寬頻','網際網路收入','家居用品','訊號費','寬頻','市話','網路線','月租費','手機']:
            targ[i]="電信網路"
        elif item in ['民生用品','面紙','毛毯','棉褲','童裝','雨衣','日用品','毛浴巾','日用品百貨','女鞋',"開器用品","輕便雨衣","洗衣精","打火機",'運動用品','衛生紙','衣物','廚具',]:
            targ[i]="生活"
        elif item in ['水費','電費','桶裝瓦斯','瓦斯費','瓦斯桶','天然氣費','水電瓦斯','瓦斯']:
            targ[i]="水電瓦斯"
        elif item in ['遊戲幣','點數卡 ','遊戲點數','耳機','遊戲軟體 ',"儲值卡",'數位商品','點數卡','C用品','線上遊戲','遊戲卡點數','C週邊商品','應用程式','電腦週邊設備','基本台費','耳麥','電腦週邊產品']:
            targ[i]="資訊"
        elif item in ['藥品','醫療注射液','衛生用品','口含錠','口罩','化妝品','清潔袋','美容','感冒糖漿','化粧品','生理食鹽水','保健食品']:
            targ[i]="藥妝"
        elif item in ['電影網路訂票手續費','手續費','洗車','運費','服務費','洗車費','其他服務費','佣金','交通票券手續費','代收運費']:
            targ[i]="手續服務費"
        elif item in ['門票','學費','貓糧','運動配件','營養品','觀景臺門票','禮','飼料','農藥','咖啡豆','卡通','茶葉','兌換碼','房租','烘焙材料','保溫杯','電池','玩具','測驗費用','會員卡費用','宅急便']:
            targ[i]="其他"
        elif item in ['停車位租金']:
            targ[i]="停車費"
        elif item in ['五金材料']:
            targ[i]="五金"
        elif item in ['水果食品','蔬菜','水果']:
            targ[i]="生鮮"
        elif item in ["報紙",'報紙 ']:
            targ[i]="報紙"
    c=Counter(targ)
    #print(c)
    name=[]
    freq=[]
    if cmd==3:
        for n,f in c.most_common(10):
            name.append(n)
            freq.append(f)
    else:
        freq=c.values()
        name=c.keys()
    x_pos=[i for i,_ in enumerate(name)]
    plt.bar(x_pos,freq,color="green")
    plt.xticks(x_pos,name,fontproperties=font)
    plt.xlabel("分類",fontproperties=font)
    plt.ylabel("出現次數",fontproperties=font)
    plt.text(len(name)//2,max(freq)/1.2,construct_text(d,freq,cmd),fontproperties=font,fontsize="8")
    plt.show()
    
def getdata(result,targ_id):
    num=10201
    #count=0
    while True:
        if num==10811:
            break
        else:
            url="https://www.etax.nat.gov.tw/etw-main/web/ETW183W3_"+str(num)+"/"
            html=requests.get(url).content.decode('utf-8')
            sp=BeautifulSoup(html,'html.parser')
            table=sp.find('table',{'id':str(targ_id)})
            rows=table.find_all('tr')
            title= [c.text for c in rows[0].find_all('th')]
            data= [list() for _ in range(len(title)-2)]
            for r in rows[1:]:
                for col,cell_data in zip(data,r.find_all('td')[2:]):
                    col.append(cell_data.text)
            data[0]=[find_comp(s) for s in data[0]]
            data[1]=[find_place(s) for s in data[1]]
            data[2]=[find_item(s) for s in data[2]]
            result.append(data)
            num=next_one(num)
def next_one(num):
    if (num%100) < 11 :
        num+=2
    elif ((num//100)%10) < 8 :
        num+=90
    return num
def find_place(string):
    s=string[:3:]
    if s=="台北市":
        s="臺北市"
    return s
def find_comp(string):
    if string.startswith("台灣麥當勞"):
        return "台灣麥當勞"
    if string.find("股份")!=-1:
        return string[:string.find("股份")]
    elif string.find("有限")!=-1:
        return string[:string.find("有限")]
    elif string.find('店招')!=-1:
        return string[string.find('店招')+3:-1:]
    elif string.startswith("台灣中油") or string.startswith("臺灣中油"):
        return "台灣中油"
    else:
        return string
def find_item(item):
    s=""
    cheatsheet=['共','計','項','元','，','*','等',',','。','個','一','瓶','批','包','盒','組']
    for char in item:
        if not char.isdigit():
            if char not in cheatsheet:
                if char =='及' or char == '和' or char=='、':
                    s+="+"
                else:
                    s+=char
    if '+' in s:
        s=s.split('+')
    return s
def construct_text(d,targ,cmd):
    if cmd==1:
        s="共有 "
        s+=str(len(d))
        s+=" 種不同商品交易項目\n"
        s+="共分類為 "
        s+=str(len(targ))
        s+=" 種交易項目"
    elif cmd==2:
        s="共有"
        s+=str(len(d))
        s+=" 個縣市交易\n"
    else:
        s="共有 "
        s+=str(len(d))
        s+=" 種商家\n"
    return s
result1000=[]
result200=[]
thread1=threading.Thread(target=getdata,args=(result1000,"fbonly"))
thread2=threading.Thread(target=getdata,args=(result200,"fbonly_200"))
thread1.start()
thread2.start()
thread1.join()
thread2.join()
ctrl="yes"
while True:
    need=[]
    st=0
    et=0
    cmd=0
    if ctrl=="yes":
        amount=input("type '1' for all,'2' for 10 mil,'3' for 2 mil.\n")
        while amount not in ["1","2","3"]:
            print("You're inputting wrong!\n")
            amount=input("type '1' for all,'2' for 10 mil,'3' for 2 mil.\n")
        starttime=input("type in the start time (YYYMM)\n")
        while True:
            try:
                starttime=int(starttime)
                if starttime%2!=1:
                    raise ValueError
                if not 10201<=starttime<=10809:
                    raise ValueError
                if not starttime%100<=11:
                    raise ValueError
                break
            except ValueError:
                print("You're inputting wrong!\n")
                starttime=input("type in the start time (YYYMM)\n")
        st=(((starttime-10201)//100)*6)+(((starttime-10201)%100)//2)
        #print(st)
        endtime=input("type in the end time (YYYMM)\n")
        while True:
            try:
                endtime=int(endtime)
                if endtime%2!=1:
                    raise ValueError
                if not 10201<=endtime<=10809:
                    raise ValueError
                if not endtime%100<=11:
                    raise ValueError
                if starttime>endtime:
                    raise ValueError
                break
            except ValueError:
                print("You're inputting wrong!\n")
                endtime=input("type in the end time (YYYMM)\n")
        et=(((endtime-10201)//100)*6)+(((endtime-10201)%100)//2)
        #print(et)
        pla_or_pro=input("Do you want to compare (1)products or (2)cities? or (3) the top 10 company (1 or 2 or 3)\n")
        while pla_or_pro not in ["1","2","3"]:
            print("You're inputting wrong!\n")
            pla_or_pro=input("Do you want to compare (1)products or (2)cities? or (3) the top 10 company (1 or 2 or 3)\n")
        if amount=="1":
            for i,s in enumerate(result1000):
                #print(i,"   1000    \n",s)
                if st<=i<=et:
                    need.append(s)
            for i,s in enumerate(result200):
                #print(i,"   2000    \n",s)
                if st<=i<=et:
                    need.append(s)
        elif amount=="2":
            for i,s in enumerate(result1000):
                if st<=i<=et:
                    need.append(s)
        else:
            for i,s in enumerate(result200):
                if st<=i<=et:
                    need.append(s)
        if pla_or_pro=="1":
            item_data=[s[2] for s in need]
            #print(item_data)
            do_stuff(item_data,1)
        elif pla_or_pro=="2":
            item_data=[s[1] for s in need]
            do_stuff(item_data,2)
        else:
            item_data=[s[0] for s in need]
            do_stuff(item_data,3)
    else:
        break
    ctrl=input("Again? (yes/no)\n")