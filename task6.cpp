#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <random>
//variant 5
void print(std::list<bool> list) {
    std::list<bool>::iterator iter;
    for(iter = list.begin();iter!= list.end();++iter){
        std::cout<< *iter<<' ';
    }
    std::cout << std::endl;
}

bool randomNum() {
    std::random_device r{};
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution distribution(0, 1);
    return distribution(randomEngine);
}
void findptr(std::list<bool> list,std::list<bool>::iterator& iter){

    int i=0;
    while(i<10){
        ++iter;
        ++i;
    }

}
int main() {
    std::list<bool> list;
    for (int i = 0; i < 20; ++i) {
        list.push_back(randomNum());
    }
    print(list);
    int counterTrue = std::count(list.begin(), list.end(), true);
    int counterFalse = std::count(list.begin(), list.end(), false);
    std::cout << "True: " << counterTrue << " False: " << counterFalse << std::endl;
    std::list<bool>::iterator iter=list.begin();;
    findptr(list,iter);
    list.erase(list.begin(),iter);
    print(list);

    return 0;
}
