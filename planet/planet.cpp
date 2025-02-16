#include "planet.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
namespace {
const int buffSize = 100;
const int q = 4;
}  // namespace
namespace PlanetZone {
Planet::Planet() {
    diametr = 0;
    life = true;
    sateliteNumber = 0;
}
Planet::Planet(const char* n, double d, bool l, int sn) {
    diametr = d;
    life = l;
    sateliteNumber = sn;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

void Planet::DeleteN() {
    delete[] name;
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

void Planet::DeleteDB(Planet*& planets, int size) {
    for (int i = 0; i < size; ++i) {
        planets[i].DeleteN();
    }
    delete[] planets;
    planets = nullptr;
}

void Planet::Print(Planet* planets, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << planets[i].GetN() << " " << planets[i].GetD() << " " << planets[i].GetL() << " " << planets[i].GetSN() << std::endl;
    }
}

void Planet::Resize(Planet*& planets, int& size) {
    Planet* newPlanets = new Planet[size + 1]();

    for (int i = 0; i < size; ++i) {
        newPlanets[i].SetN(planets[i].GetN());
        newPlanets[i].SetD(planets[i].GetD());
        newPlanets[i].SetL(planets[i].GetL());
        newPlanets[i].SetSN(planets[i].GetSN());
    }
    std::cout << size << " " << newPlanets[size - 1].GetN() << std::endl;

    Planet* oldPlanets = planets;
    planets = newPlanets;
    DeleteDB(oldPlanets,size);
    ++size;

}

void Planet::ReadDB(char* fileName, Planet* planets, int& size) {
    std::ifstream inStream(fileName);
    char ch{};
    int lineC = 0;
    int num = 0;
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

    inStream.close();
    inStream.open(fileName);

    while (num < 2) {
        if (c % q == 0) {
            if (c != 0) {
                if (planets == nullptr) {
                    std::cerr << "Ошибка: указатель planets == nullptr перед Resize!" << std::endl;
                }
                Resize(planets, size);
            }
            inStream >> nameP;
            ++c;
            std::cout << nameP << std::endl;
            planets[size - 1].SetN(nameP);
            std::cout << size << planets[size - 1].GetN() << std::endl;
        }
        if (c % q == 1) {
            inStream >> dP;
            ++c;
            std::cout << dP << std::endl;
            planets[size - 1].SetD(dP);
        }
        if (c % q == 2) {
            inStream >> lP;
            ++c;
            std::cout << lP << std::endl;
            planets[size - 1].SetL(lP);
        }
        if (c % q == 3) {
            inStream >> sateliteP;
            ++c;
            std::cout << sateliteP << std::endl;
            std::cout << "NUM" << num;
            planets[size - 1].SetSN(sateliteP);
            ++num;
        }
    }
    inStream.close();
}
}  // namespace PlanetZone
