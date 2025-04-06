#include "animals.hpp"
Animals::Animals(const char* name){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    std::cout << "Animals()" << std::endl;
}
Animals::~Animals(){
    delete[] name;
    std::cout << "~Animals()" << std::endl;
}
