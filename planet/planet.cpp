#include "planet.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
namespace {
const int buffSize = 100;
const int q = 4;

}  // namespace
namespace PlanetZone {
int Planet::total = 0;
Planet::Planet() {
    name = nullptr;
    diametr = 0;
    life = true;
    sateliteNumber = 0;
    total++;
    id = total;
    std::cout << "Создание ID " << id << std::endl;
}
Planet::Planet(const char* n, double d, bool l, int sn) {
    diametr = d;
    life = l;
    sateliteNumber = sn;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}
Planet::~Planet() {
    total--;
    std::cout << "Удаление ID " << id << std::endl;
}

void Planet::DeleteN() {
    delete[] name;
    name = nullptr;
}
char* Planet::GetN() {
    return name;
}
double Planet::GetD() {
    return diametr;
}
bool Planet::GetL() {
    return life;
}
int Planet::GetSN() {
    return sateliteNumber;
}

void Planet::SetN(char* n) {
    if (name) {
        delete[] name;
    }
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}
void Planet::SetD(double d) {
    diametr = d;
}
void Planet::SetL(bool l) {
    life = l;
}
void Planet::SetSN(int sn) {
    sateliteNumber = sn;
}

std::ofstream& operator<<(std::ofstream& out, Planet& el) {
    out << el.GetN() << " " << el.GetD() << " " << el.GetL() << " " << el.GetSN() << std::endl;
    return out;
}
std::ifstream& operator>>(std::ifstream& in, Planet& el) {
    char nameP[buffSize]{};
    double dP{};
    bool lP{};
    int sateliteP{};
    in >> nameP >> dP >> lP >> sateliteP;
    el.SetN(nameP);
    el.SetD(dP);
    el.SetL(lP);
    el.SetSN(sateliteP);

    return in;
}
bool operator==(Planet& el, Planet& el2) {
    if (el.GetD() == el2.GetD()) {
        return true;
    }
    return false;
}
bool operator<(Planet& el, Planet& el2) {
    if (el.GetD() < el2.GetD()) {
        return true;
    }
    return false;
}
Planet& Planet::operator=(Planet& el) {
    this->SetN(el.GetN());
    this->SetD(el.GetD());
    this->SetL(el.GetL());
    this->SetSN(el.GetSN());
    return *this;
}
void Planet::SortDB(Planet*& planets, int& size) {
    if (planets) {
        Planet temp;
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - 1 - i; ++j) {
                if (planets[j] < planets[j + 1]) {
                    temp = planets[j];
                    planets[j] = planets[j + 1];
                    planets[j + 1] = temp;
                }
            }
        }
    }
}
void Planet::DeleteEl(Planet*& planets, int& size, const char* remove) {
    if (planets) {
        for (int i = 0; i < size; ++i) {
            if (!strcmp(planets[i].GetN(), remove)) {
                planets[i].DeleteN();
                Planet* newPlanets = new Planet[size - 1]();

                for (int j = i; j < size - 1; ++j) {
                    planets[j] = planets[j + 1];
                }

                for (int i = 0; i < size - 1; ++i) {
                    newPlanets[i] = planets[i];
                }
                DeleteDB(planets, size);
                planets = newPlanets;

                size--;
                break;
            } else if (i == size - 1) {
                std::cout << "No element" << std::endl;
            }
        }
    }
}
void Planet::AddEl(Planet*& planets, int& size) {
    if (planets) {
        Resize(planets, size);

        char nameP[buffSize];
        double dP;
        bool lP;
        int sateliteP;
        std::cout << "Введите навзание планеты, ее диаметр, характер жизни(0/1) и количество спутников" << std::endl;
        std::cin >> nameP >> dP >> lP >> sateliteP;
        planets[size - 1].SetN(nameP);
        planets[size - 1].SetD(dP);
        planets[size - 1].SetL(lP);
        planets[size - 1].SetSN(sateliteP);
    }
}

void Planet::WriteDB(char* fileName, Planet*& planets, int& size) {
    if (planets) {
        std::ofstream outStream(fileName);

        for (int i = 0; i < size; ++i) {
            outStream << planets[i];
        }
        outStream.close();
    }
}

void Planet::DeleteDB(Planet*& planets, int& size) {
    if (planets) {
        for (int i = 0; i < size; ++i) {
            planets[i].DeleteN();
        }
        delete[] planets;
        planets = nullptr;
    }
}

void Planet::Print(Planet*& planets, int size) {
    if (planets) {
        for (int i = 0; i < size; ++i) {
            std::cout << planets[i].GetN() << " " << planets[i].GetD() << " " << planets[i].GetL() << " " << planets[i].GetSN() << std::endl;
        }
    }
}

void Planet::Resize(Planet*& planets, int& size) {
    if (planets) {
        Planet* newPlanets = new Planet[size + 1]();

        for (int i = 0; i < size; ++i) {
            newPlanets[i] = planets[i];
        }

        DeleteDB(planets, size);
        planets = newPlanets;
        ++size;
    }
}

void Planet::ReadDB(char* fileName, Planet*& planets, int& size) {
    if (planets) {
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
                Resize(planets, size);
            }
            inStream >> planets[i];
        }

        inStream.close();
    }
}
}  // namespace PlanetZone
