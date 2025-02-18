#include "mat.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
namespace {
const int buffSize = 100;
const int q = 4;

}  // namespace
namespace ShopZone {

Shop::Shop() {
    name = nullptr;
    area = 0;
    income = 0;
    branchNum = 0;
}
Shop::~Shop() {
    delete[] name;
    name = nullptr;
}

void Shop::DeleteN() {
    delete[] name;
    name = nullptr;
}
char* Shop::GetN() {
    return name;
}
double Shop::GetA() {
    return area;
}
double Shop::GetI() {
    return income;
}
int Shop::GetBranch() {
    return branchNum;
}

void Shop::SetN(char* n) {
    if (name) {
        delete[] name;
    }
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}
void Shop::SetA(double d) {
    area = d;
}
void Shop::SetI(double l) {
    income = l;
}
void Shop::SetBranch(int sn) {
    branchNum = sn;
}

std::ofstream& operator<<(std::ofstream& out, Shop& el) {
    out << el.GetN() << " " << el.GetA() << " " << el.GetI() << " " << el.GetBranch() << std::endl;
    return out;
}
std::ifstream& operator>>(std::ifstream& in, Shop& el) {
    char nameS[buffSize]{};
    double areaS{};
    double incomeS{};
    int numS{};
    in >> nameS >> areaS >> incomeS >> numS;
    el.SetN(nameS);
    el.SetA(areaS);
    el.SetI(incomeS);
    el.SetBranch(numS);

    return in;
}
bool operator==(Shop& el, Shop& el2) {
    if (!strcmp(el.GetN(), el2.GetN())) {
        return true;
    }
    return false;
}
bool operator<(Shop& el, Shop& el2) {
    if (strcmp(el2.GetN(), el.GetN()) > 0) {
        return true;
    }
    return false;
}
Shop& Shop::operator=(Shop& el) {
    this->SetN(el.GetN());
    this->SetA(el.GetA());
    this->SetI(el.GetI());
    this->SetBranch(el.GetBranch());
    return *this;
}
void Shop::SortDB(Shop*& shops, int& size) {
    if (shops) {
        Shop temp;
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - 1 - i; ++j) {
                if (shops[j] < shops[j + 1]) {
                    temp = shops[j];
                    shops[j] = shops[j + 1];
                    shops[j + 1] = temp;
                }
            }
        }
    }
}
void Shop::DeleteEl(Shop*& shops, int& size, const char* remove) {
    if (shops) {
        for (int i = 0; i < size; ++i) {
            if (!strcmp(shops[i].GetN(), remove)) {
                shops[i].DeleteN();
                Shop* newShops = new Shop[size - 1]();

                for (int j = i; j < size - 1; ++j) {
                    shops[j] = shops[j + 1];
                }

                for (int i = 0; i < size - 1; ++i) {
                    newShops[i] = shops[i];
                }
                DeleteDB(shops, size);
                shops = newShops;

                size--;
                break;
            } else if (i == size - 1) {
                std::cout << "No element" << std::endl;
            }
        }
    }
}
void Shop::AddEl(Shop*& shops, int& size) {
    if (shops) {
        Resize(shops, size);

        char nameS[buffSize]{};
        double areaS{};
        double incomeS{};
        int numS{};
        std::cout << "Введите навзание магазина, его площадь, заработок и количество филиалов" << std::endl;
        std::cin >> nameS >> areaS >> incomeS >> numS;
        shops[size - 1].SetN(nameS);
        shops[size - 1].SetA(areaS);
        shops[size - 1].SetI(incomeS);
        shops[size - 1].SetBranch(numS);
    }
}

void Shop::WriteDB(char* fileName, Shop*& shops, int& size) {
    if (shops) {
        std::ofstream outStream(fileName);

        for (int i = 0; i < size; ++i) {
            outStream << shops[i];
        }
        outStream.close();
    }
}

void Shop::DeleteDB(Shop*& shops, int& size) {
    if (shops) {
        for (int i = 0; i < size; ++i) {
            shops[i].DeleteN();
        }
        delete[] shops;
        shops = nullptr;
    }
}

void Shop::Print(Shop*& shops, int size) {
    if (shops) {
        for (int i = 0; i < size; ++i) {
            std::cout << shops[i].GetN() << " " << shops[i].GetA() << " " << shops[i].GetI() << " " << shops[i].GetBranch() << std::endl;
        }
    }
}

void Shop::Resize(Shop*& shops, int& size) {
    if (shops) {
        Shop* newShops = new Shop[size + 1]();

        for (int i = 0; i < size; ++i) {
            newShops[i] = shops[i];
        }

        DeleteDB(shops, size);
        shops = newShops;
        ++size;
    }
}

void Shop::ReadDB(char* fileName, Shop*& shops, int& size) {
    if (shops) {
        std::ifstream inStream(fileName);
        char ch{};
        int lineC = 0;
        int num = 0;

        int c = 0;
        while (inStream.get(ch)) {
            if (ch == '\n') {
                lineC++;
            }
        }

        inStream.close();
        inStream.open(fileName);
        for (int i = 0; i < lineC; ++i) {
            if (i != 0) {
                Resize(shops, size);
            }
            inStream >> shops[i];
        }

        inStream.close();
    }
}
}  // namespace ShopZone
