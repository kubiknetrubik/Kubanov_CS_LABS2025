#pragma once
#include <cstring>
#include <iostream>
namespace ShopZone {
class Shop {
 private:
    char* name;
    double area;
    double income;
    int branchNum;

 public:
    Shop();
    ~Shop();

    void DeleteN();
    char* GetN();
    double GetA();
    double GetI();
    int GetBranch();
    void SetN(char* n);
    void SetA(double d);
    void SetI(double l);
    void SetBranch(int sn);

    friend std::ofstream& operator<<(std::ofstream& out, Shop& el);
    friend std::ifstream& operator>>(std::ifstream& in, Shop& el);
    Shop& operator=(Shop& el);
    friend bool operator==(Shop& el, Shop& el2);
    friend bool operator<(Shop& el, Shop& el2);

    static void DeleteDB(Shop*& shops, int& size);

    static void Print(Shop*& shops, int size);
    static void Resize(Shop*& shops, int& size);
    static void ReadDB(char* fileName, Shop*& shops, int& size);
    static void WriteDB(char* fileName, Shop*& shops, int& size);
    static void AddEl(Shop*& shops, int& size);
    static void SortDB(Shop*& shops, int& size);
    static void DeleteEl(Shop*& shops, int& size, const char* remove);
};

}  // namespace ShopZone
