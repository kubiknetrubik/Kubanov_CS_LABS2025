#include "ClassDoer.hpp"
#include <cstring>
#include <iostream>
#include "mymat/mat.hpp"
#include "planet/planet.hpp"
namespace {
const int buffSize = 100;
}
namespace ClassDoer {
void ExecutePlanet() {
    int task = 0;
    char* fileName = "DataBase.txt";
    int size = 1;
    PlanetZone::Planet* planets = new PlanetZone::Planet[size];
    while (static_cast<Command>(task) != Command::Exit) {
        std::cout << "Выберите номер, интересующего вас задания, и введите его в консоль для перехода\n";
        std::cout << "1. Чтение БД из файла\n";
        std::cout << "2. Запись БД в файл\n";
        std::cout << "3. Сортировка БД\n";
        std::cout << "4. Добавление нового объекта в БД\n";
        std::cout << "5. Удаление объекта из БД\n";
        std::cout << "6. Вывод БД на экран\n";
        std::cout << "7. Редактирование название заданной планеты\n";
        std::cout << "8. Выход\n";
        std::cin >> task;
        switch (static_cast<Command>(task)) {
            case Command::Read: {
                PlanetZone::Planet::ReadDB(fileName, planets, size);

                break;
            }
            case Command::Write: {
                PlanetZone::Planet::WriteDB(fileName, planets, size);

                break;
            }
            case Command::Sort: {
                PlanetZone::Planet::SortDB(planets, size);

                break;
            }
            case Command::Add: {
                
                PlanetZone::Planet::AddEl(planets, size);

                break;
            }
            case Command::Delete: {
                char remove[buffSize]{};
                std::cout << "Введите название планеты для удаления: " << std::endl;
                std::cin >> remove;
                PlanetZone::Planet::DeleteEl(planets, size, remove);

                break;
            }
            case Command::Print: {
                PlanetZone::Planet::Print(planets, size);
                break;
            }
            case Command::Edit:{
                char ed[buffSize]{};
                std::cout << "Введите название планеты для редактирования: " << std::endl;
                std::cin >> ed;
                PlanetZone::Planet::EditEl(planets, size, ed);
                break;
            }
            case Command::Exit: {
                PlanetZone::Planet::DeleteDB(planets, size);
                break;
            }
            default: {
                std::cout << "Такого номера задания нет(Введите значение от 1 до 7)\n";
                break;
            }
        }
    }
}
void ExecuteShop() {
    int task = 0;
    char* shopFile = "ShopsBase.txt";
    int size = 1;
    ShopZone::Shop* shops = new ShopZone::Shop[size];
    while (static_cast<Command>(task) != Command::Exit) {
        std::cout << "Выберите номер, интересующего вас задания, и введите его в консоль для перехода\n";
        std::cout << "1. Чтение БД из файла\n";
        std::cout << "2. Запись БД в файл\n";
        std::cout << "3. Сортировка БД\n";
        std::cout << "4. Добавление нового объекта в БД\n";
        std::cout << "5. Удаление объекта из БД\n";
        std::cout << "6. Вывод БД на экран\n";
        std::cout << "7. Редактирование плоащди заданного магазина\n";
        std::cout << "8. Выход\n";
        std::cin >> task;
        switch (static_cast<Command>(task)) {
            case Command::Read: {
                ShopZone::Shop::ReadDB(shopFile, shops, size);

                break;
            }
            case Command::Write: {
                ShopZone::Shop::WriteDB(shopFile, shops, size);

                break;
            }
            case Command::Sort: {
                ShopZone::Shop::SortDB(shops, size);

                break;
            }
            case Command::Add: {
                ShopZone::Shop::AddEl(shops, size);

                break;
            }
            case Command::Delete: {
                char remove[buffSize]{};
                std::cout << "Введите название планеты для удаления: " << std::endl;
                std::cin >> remove;
                ShopZone::Shop::DeleteEl(shops, size, remove);

                break;
            }
            case Command::Print: {
                ShopZone::Shop::Print(shops, size);
                break;
            }
            case Command::Edit:{
                char ed[buffSize]{};
                std::cout << "Введите название магазина для редактирования: " << std::endl;
                std::cin >> ed;
                ShopZone::Shop::EditEl(shops, size, ed);
                break;
            }
            case Command::Exit: {
                ShopZone::Shop::DeleteDB(shops, size);
                break;
            }
            default: {
                std::cout << "Такого номера задания нет(Введите значение от 1 до 7)\n";
                break;
            }
        }
    }
}
void ExecuteMenu() {
    int checker = 0;
    while (static_cast<Type>(checker) != Type::e) {
        std::cout << "Магазины или планеты?(0-планеты,1-магазины,2-выход)" << std::endl;
        std::cin >> checker;
        switch (static_cast<Type>(checker)) {
            case Type::p: {
                ExecutePlanet();
                break;
            }
            case Type::s: {
                ExecuteShop();
                break;
            }
            case Type::e: {
                break;
            }
            default: {
                std::cout << "Такого номера задания нет(Введите значение от 0 до 2)\n";
                break;
            }
        }
    }
}
}  // namespace ClassDoer
