#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main(){
    std::string str{};
    std::ifstream in("in.txt");
    std::ofstream out("out.txt");
    if(in&&out){
        while(in>>str){
            out<<str<<'\n';

        }
    }


    return 0;

}
