#include <iostream>
#include <map>
#include <string>

int main(){
    std::map<std::string, int> planets;
    planets["Меркурий"] = 0;
    planets["Венера"] = 0;
    planets["Земля"] = 1;
    planets["Марс"] = 2;
    planets["Юпитер"] = 69;
    planets["Сатурн"] = 62;
    planets["Уран"] = 27;
    planets["Нептун"] = 14;
    planets["Плутон"] = 10;

    std::cout << "Planets"<<'\n';
    for (std::map<std::string, int>::iterator iter = planets.begin(); iter != planets.end(); ++iter) {
        std::cout <<'"'<<iter->first<<'"' << "," << iter->second << "\n";
    }

    std::map<std::string, int>::iterator maxPlanet = planets.begin();
    for (std::map<std::string, int>::iterator iter = planets.begin(); iter != planets.end(); ++iter) {
        if (maxPlanet->second<iter->second) {
            maxPlanet = iter;
        }
    }

    std::cout << "MaxPlanet " << maxPlanet->first << " " << maxPlanet->second<<std::endl;

    return 0;
}
