#include "artiodactyls.hpp"
Artiodactyls::Artiodactyls(const char* name, int warmBloodnessMeasure,int hoopQuntity): Mammals(name,warmBloodnessMeasure),hoopQuntity(hoopQuntity){
    std::cout<<"Artiodactyls()"<<std::endl;
}
Artiodactyls::~Artiodactyls(){
    std::cout<<"~Artiodactyls()"<<std::endl;
}
void Artiodactyls::show() const{
    std::cout<<"Наименование парнокопытного- "<<name<<" , с теплокровностью"<<warmBloodnessMeasure<<" , с количеством копыт"<<hoopQuntity<<std::endl;
}
