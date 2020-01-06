from bs4 import BeautifulSoup
import requests
url="https://www.etax.nat.gov.tw/etw-main/web/ETW183W3_10809/"
html=requests.get(url).content.decode('utf-8')
sp=BeautifulSoup(html,'html.parser')
table=sp.find('table',{'id':'fbonly'})
rows=table.find_all('tr')
title= [c.text for c in rows[0].find_all('th')]
data= [list() for _ in range(len(title)-2)]
for r in rows[1:]:
    for col,cell_data in zip(data,r.find_all('td')[2:]):
        col.append(cell_data.text)
for comp in data[0]:
    if comp.find('公司')!=-1:
        comp=comp[:comp.find('公司')+2]
    else:
        print(comp)
print(data)



def find_comp(string):
    if string.find("股份")!=-1:
        return string[:string.find("股份")]
    elif string.find("有限")!=-1:
        return string[:string.find("有限")]
    else:
        return string
    
    
    data[0]=[find_comp(s) for s in data[0]]