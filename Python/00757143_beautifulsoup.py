from bs4 import BeautifulSoup

import requests

url = 'https://data.gov.tw/news'

html = requests.get(url).content.decode('utf-8')

sp = BeautifulSoup(html,'html.parser')

for idx,link in enumerate(sp.find_all('td')):

    print('{}'.format(link.text))