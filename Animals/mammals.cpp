#include "mammals.hpp"
Mammals::Mammals(const char* name, int warmBloodnessMeasure): Animals(name),warmBloodnessMeasure(warmBloodnessMeasure){
    std::cout<<"Mammals()"<<std::endl;
}
Mammals::~Mammals(){
    std::cout<<"~Mammals()"<<std::endl;
}
void Mammals::show() const{
    std::cout<<"Наименование млекопитающего- "<<name<<" , с теплокровностью"<<warmBloodnessMeasure<<std::endl;
}
