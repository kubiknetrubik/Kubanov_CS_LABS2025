#include "planet.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
namespace{
const int buffSize=100;
const int q=4;
}
namespace PlanetZone{
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
Planet::~Planet(){
    delete[] name;
}

void Planet::DeleteN(){
    delete[] name;
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

void Planet::SetN(char* n){
    name = new char[strlen(n)];
    strcpy(name,n);

}
void Planet::SetD(double d){
    diametr=d;

}
void Planet::SetL(bool l){
    life=l;

}
void Planet::SetSN(int sn){
    sateliteNumber=sn;

}

void Planet::DeleteDB(Planet* planets,int size){
    for(int i = 0;i<size;++i){
        planets[i].DeleteN();
    }
    delete[] planets;
    planets=nullptr;

}

void Planet::Print(Planet* planets,int size){
    for(int i = 0;i<size;++i){
        std::cout<<planets[i].GetN()<<" "<<planets[i].GetD()<<" "<<planets[i].GetL()<<" "<<planets[i].GetSN()<<std::endl;
    }

}

void Planet::Resize(Planet* planets,int& size){
    Planet* newPlanets = new Planet[size+1]();
    std::cout<<size<<"KEK"<<std::endl;
    for(int i = 0;i<size;++i){
        std::cout<<"lol";
        newPlanets[i].SetN("KpK");
        newPlanets[i].SetD(planets[i].GetD());
        newPlanets[i].SetL(planets[i].GetL());
        newPlanets[i].SetSN(planets[i].GetSN());

    }
    std::cout<<"lol";
    Planet* oldPlanets=planets;
    planets=newPlanets;

    ++size;
    delete[] oldPlanets;


}

void Planet::ReadDB(char* fileName,Planet* planets,int& size){
    std::ifstream inStream(fileName);
    char ch{};
    int lineC=0;
    char nameP[buffSize];
    double dP;
    bool lP;
    int sateliteP;
    int c = 0;
    while (inStream.get(ch)) {
        if (ch == '\n') {
            lineC++;
        }
    }
    std::cout<<lineC;
    inStream.close();
    inStream.open(fileName);
    while(size-1<lineC){
        if(c%q==0){
            inStream>>nameP;
            ++c;
            planets[size-1].SetN(nameP);
        }
        if(c%q==1){
            inStream>>dP;
            ++c;
            planets[size-1].SetD(dP);
        }
        if(c%q==2){
            inStream>>lP;
            ++c;
            planets[size-1].SetL(lP);
        }
        if(c%q==3){
            inStream>>sateliteP;
            ++c;
            planets[size-1].SetSN(sateliteP);
            Print(planets,size);
            Resize(planets,size);
            std::cout<<"size";
        }


    }
    inStream.close();
}
}
