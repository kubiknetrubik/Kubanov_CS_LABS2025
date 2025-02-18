#pragma once
#include <cstring>
#include <iostream>
namespace PlanetZone {
class Planet {
 private:
    char* name;
    double diametr;
    bool life;
    int sateliteNumber;

 public:
    Planet();
    Planet(const char* n, double d, bool l, int sn);
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

    friend std::ofstream& operator<<(std::ofstream& out, Planet& el);
    friend std::ifstream& operator>>(std::ifstream& in, Planet& el);
    Planet& operator=(Planet& el);
    friend bool operator==(Planet& el, char* nn);
    friend bool operator<(Planet& el, Planet& el2);

    static void DeleteDB(Planet*& planets, int& size);

    static void Print(Planet*& planets, int size);
    static void Resize(Planet*& planets, int& size);
    static void ReadDB(char* fileName, Planet*& planets, int& size);
    static void WriteDB(char* fileName, Planet*& planets, int& size);
    static void AddEl(Planet*& planets, int& size);
    static void SortDB(Planet*& planets, int& size);
    static void DeleteEl(Planet*& planets, int& size, char* remove);
    static void EditEl(Planet*& planets, int& size, char* ed);
};

}  // namespace PlanetZone
