import requests

import re

url = 'https://data.gov.tw/news'

html = requests.get(url).content.decode('utf-8')

for idx,title in enumerate(re.finditer(r'<td class="td-title"><a[^>]*?>([^<]*?)<\/a><\/td>',html)):

    print('{:4d}. {}'.format(idx+1,title.group(1)))

for idx,title in enumerate(re.finditer(r'<td class="td-date">([^<]*?)<\/td>',html)):

    print('{:4d}. {}'.format(idx+1,title.group(1)))