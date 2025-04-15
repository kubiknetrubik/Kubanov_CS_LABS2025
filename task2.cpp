#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string str{};
    std::getline(std::cin,str);

    for(int i = 0;i<(str.length()/2);++i){
        std::swap(str[i],str[str.length()-i-1]);
    }
    for(int i =0;i<str.length();++i){
        std::cout<<str[i];
    }
    return 0;

}
