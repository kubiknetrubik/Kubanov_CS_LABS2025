#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string str{};
    std::getline(std::cin,str);
    std::vector<int> positions{};
    for(int i = 0;i<str.length();++i){
        if(str[i]=='@'){
            positions.push_back(i);
        }
    }
    for(int i =0;i<positions.size();++i){
        std::cout<<positions[i]<<' ';
    }
    positions.clear();
    return 0;

}
