#include "ClassDoer.hpp"
#include <cstring>
#include <iostream>
#include "planet/planet.hpp"
namespace {
const int buffSize = 100;
}
namespace ClassDoer {
void ExecuteMenu() {
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
        std::cout << "7. Выход\n";
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
                std::cout << size;
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
}  // namespace ClassDoer
