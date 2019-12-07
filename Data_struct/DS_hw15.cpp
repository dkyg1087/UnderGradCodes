#include<iostream>
#include<string>
#include<algorithm>
int main(){
    int count;
    std::cin>>count;
    for(;count>0;count--){
        std::string str;
        std::cin>>str;
        for(int i=0;i<str.length();i++){
            switch (str[i]){
                case 'a':
                    std::reverse(str.begin()+i+1,str.end());
                    break;
                case 'b':
                    {std::string t_str(str,i+1,str.length()-i-1);
                    str.append(t_str);
                    break;
                    }
                case 'c':
                        if(i+2<str.length()){
                            str.erase(str.begin()+i+1);
                            str.erase(str.begin()+i+1);
                        }
                        else if(i+2==str.length()){
                            str.erase(str.begin()+i+1);
                        }
                    break;
                default:
                    break;
            }
        }
        std::cout<<str<<std::endl;
    }
}