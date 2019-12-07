import re
s1='A12345A\nBA12345\nCADA\nA'
s2='(asd)sdasd)(asdsd)asdasd)(asdas)'
s3='(1,234)5678(123)987(100,888,909)'
s4='大雄有3隻羊2條狗，小明有狗3隻雞2隻，小花有1頭牛3隻豬2隻雞狗5條。'
for i,num in zip(re.finditer('A',s1),range(1,100)):
    print("no.",num,i.start(),"-",i.end()) 
#1.
print("----------------------")
if s1[0]=='A':
    print("no. 1 0 - 1")
    for i,num in zip(re.finditer('\nA',s1),range(2,100)):
        print("no.",num,i.start(),"-",i.end())
else:
    for i,num in zip(re.finditer('\nA',s1),range(1,100)):
        print("no.",num,i.start(),"-",i.end())
#2.
print("----------------------")
for i in re.findall(r'\(.+\)',s2):
    print(i)
print("----------------------")
for i in re.findall(r'\(.+?\)',s2):
    print(i)
#3.  一個是把含有()的字串印出來
# 另一個是只把()內的東西印出來
sum=0
for i in re.findall(r'\(.+?\)',s3):
    string=''
    for j in i:
        if str.isdigit(j):
            string+=j
    sum+=int(string)
print(sum)#4.

#5 不會QQ