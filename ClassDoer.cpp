#include <iostream>
#include "ClassDoer.hpp"
#include "planet/planet.hpp"
namespace{}
namespace ClassDoer{
void ExecuteMenu() {
    int task = 0;
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
                std::cout << "1 " << std::endl;
                Planet::Planet p1("zalupa",20,true,3);
                std::cout<<p1.GetN()<<"   "<<p1.GetD();

                break;
            }
            case Command::Write: {
                std::cout << "2" << std::endl;

                break;
            }
            case Command::Sort: {
                std::cout << "3 " << std::endl;

                break;
            }
            case Command::Add: {
                std::cout << "4 " << std::endl;

                break;
            }
            case Command::Delete: {
                std::cout << "5" << std::endl;

                break;
            }
            case Command::Print: {
                std::cout << "6" << std::endl;
                break;
            }
            case Command::Exit: {
                std::cout << "7" << std::endl;
                break;
            }
            default: {
                std::cout << "Такого номера задания нет(Введите значение от 1 до 7)\n";
                break;
            }
        }
    }

}
}
