#pragma once
#include <iostream>
#include <cstring>
namespace Planet{
class Planet{
private:
    char* name;
    double diametr;
    bool life;
    int sateliteNumber;
public:
    Planet();
    Planet(const char* n,double d,bool l,int sn);
    char* GetN();
    double GetD();
    bool GetL();
    int GetSN();
};
}
