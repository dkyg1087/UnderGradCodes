from os import error
from bs4 import BeautifulSoup
import requests

def getOutputTxt():
    with open("vocab.txt","r+",encoding="utf-8") as file:
        with open("ankiWord.txt","w+",encoding="utf-8") as writeFile:    
            for word in file:
                try:
                    word = word[0:-1]
                    headers = {'User-Agent': 'User-Agent:Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36'}
                    res = requests.get("https://dictionary.cambridge.org/zht/%E8%A9%9E%E5%85%B8/%E8%8B%B1%E8%AA%9E-%E6%BC%A2%E8%AA%9E-%E7%B9%81%E9%AB%94/"+str(word),headers=headers)
                    print(str(word))
                    if not res.ok:
                        print(str(word)+" not found.")
                    else:
                        wordList = []
                        soup = BeautifulSoup(res.text,"html.parser")
                        wordList.append(soup.find("span",{"class":"hw dhw"}).getText())
                        wordList.append(soup.find("span",{"class":"pos dpos"}).getText())
                        wordList.append(soup.find("span",{"class":"trans dtrans dtrans-se break-cj"}).getText())
                        wordList.append(soup.find("div",{"class":"def ddef_d db"}).getText())
                        try:
                            examples = soup.find_all("div",{"class":"examp dexamp"})
                            count = 0
                            for example in examples:
                                if count >1:
                                    break
                                count+=1
                                wordList.append(example.getText().replace("\n", "<br>"))
                        except TypeError:
                            pass
                        writeFile.write("<h1>"+wordList[0]+"</h1>\n")
                        outputString ="( "+wordList[1]+". )<h1>"+wordList[2]+"</h1><h2>"+wordList[3]+"</h2><br>"
                        outputString+="<br><ul>"
                        try:
                            outputString+=("<li><h3>"+wordList[4])+"</h3></li>"
                            outputString+=("<li><h3>"+wordList[5])+"</h3></li>"
                        except IndexError:
                            pass
                        outputString+="</ul>"
                        outputString+="\n"
                        writeFile.write(outputString)
                except:
                    print(word+" failed to create")
                    pass

getOutputTxt()