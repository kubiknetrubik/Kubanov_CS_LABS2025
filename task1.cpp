#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string str{};
    std::getline(std::cin,str);
    std::vector<int> positions{};

    int found=0;
    int start=0;
    while(true){
        found=str.find('@',start);
        if(found!=std::string::npos){
            positions.push_back(found);
            start=found+1;
        }else{
            break;
        }

    }
    for(int i =0;i<positions.size();++i){
        std::cout<<positions[i]<<' ';
    }
    positions.clear();
    return 0;

}
