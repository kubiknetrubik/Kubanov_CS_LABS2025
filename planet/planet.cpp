#include "planet.hpp"
#include <iostream>
namespace{
const int buffSize=100;
}
namespace Planet{
Planet::Planet(){
    diametr=0;
    life=true;
    sateliteNumber=0;
}
Planet::Planet(const char* n,double d,bool l,int sn){
    diametr=d;
    life=l;
    sateliteNumber=sn;
    name = new char[strlen(n)];
    strcpy(name,n);

}

char* Planet::GetN(){
    return name;
}
double Planet::GetD(){
    return diametr;
}
bool Planet::GetL(){
    return life;
}
int Planet::GetSN(){
    return sateliteNumber;
}
}
