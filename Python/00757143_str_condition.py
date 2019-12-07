s="python,programming,language"
print("pro" in s)#Check if "pro" is in s
print(s.find("prog"))#find where prog is located in the string
print(s.split(","))#Split the string where the "," is into list
print("-".join(s.split(",")[0:2]))#Split the string from 0 to 2(0,1) where "," 
                                  #is and join it back with "-" in the middle.
print(s.startswith("py"))#Check if the string starts with "py"
print(s.endswith("age"))#Check if the string starts with "age"
print(s.upper())#Make the whole string uppercase.
print(s.title())#Returns a string where the first character in every word is upper case. 
print(s.isalpha())#Check if all the char in a string is alphabet or not.
print(s.replace("programming","interpreted"))#replace the word "programming" with "interpreted"
