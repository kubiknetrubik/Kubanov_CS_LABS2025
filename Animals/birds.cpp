#include "birds.hpp"
Birds::Birds(const char* name, int wings): Animals(name),wings(wings){
    std::cout<<"Birds()"<<std::endl;
}
Birds::~Birds(){
    std::cout<<"~Birds()"<<std::endl;
}
void Birds::show() const{
    std::cout<<"Наименование птицы- "<<name<<" , с количеством крыльев "<<wings<<std::endl;
}
