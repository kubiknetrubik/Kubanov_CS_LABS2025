#pragma once
#include <iostream>
#include <cstring>
namespace PlanetZone{
class Planet{
private:
    char* name;
    double diametr;
    bool life;
    int sateliteNumber;
public:
    Planet();
    Planet(const char* n,double d,bool l,int sn);
    ~Planet();
    void DeleteN();
    char* GetN();
    double GetD();
    bool GetL();
    int GetSN();
    void SetN(char* n);
    void SetD(double d);
    void SetL(bool l);
    void SetSN(int sn);

    static void DeleteDB(Planet* planets,int size);

    static void Print(Planet* planets,int size);
    static void Resize(Planet*& planets,int& size);
    static void ReadDB(char* fileName,Planet* planets,int& size);
};
}
