#include <iostream>
#include <map>
#include <string>

void print(std::map<std::string, int> cities) {
    std::cout << "Список городов и их расстояние от Москвы:\n";
    std::map<std::string, int>::const_iterator iter;
    for (iter = cities.begin(); iter != cities.end(); ++iter) {
        std::cout <<'"' <<iter->first <<'"'<< ": " << iter->second << ",\n";
    }
    std::cout << std::endl;
}

int main() {
    std::map<std::string, int> cities;
    cities["Минск"] = 713;
    cities["Киев"] = 856;
    cities["Санкт-Петербург"] = 786;
    cities["Астана"] = 2748;
    cities["Нижний Новгород"] = 421;
    cities["Владивосток"] = 9141;

    print(cities);

    std::map<std::string, int>::iterator minCity = cities.begin();
    std::map<std::string, int>::iterator maxCity = cities.begin();
    std::map<std::string, int>::iterator iter;
    for  (iter = cities.begin(); iter != cities.end(); ++iter) {
        if (iter->second < minCity->second) {
            minCity = iter;
        }
        if (maxCity->second<iter->second) {
            maxCity = iter;
        }
    }

    std::cout << "Ближайший: " <<'"' <<minCity->first <<'"'<< ": " << minCity->second << ",\n";;
    std::cout << "Дальний: " <<'"' <<maxCity->first <<'"'<< ": " << maxCity->second << ",\n";

    return 0;
}
