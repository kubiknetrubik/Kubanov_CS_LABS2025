#include "StartApp.hpp"
namespace StartApp{
void AddEl(MyStack<Animals*>& animals) {
    char name[100];
    std::cout << "Введите имя животного: ";
    std::cin.getline(name, 100);
    int type;
    std::cout << "Выберите вид животного:" << std::endl;
    std::cout << "1. Птица" << std::endl;
    std::cout << "2. Млекопитающее" << std::endl;
    std::cout << "3. Парнокопытное" << std::endl;
    std::cin >> type;

    switch (static_cast<AnimalType>(type)) {
        case AnimalType::Birds: {
            int wingsTemp;
            std::cout << "Введите количество крыльев: "<<std::endl;
            std::cin >>wingsTemp;
            animals.push(new Birds(name,wingsTemp));
            break;
        }
        case AnimalType::Mammals: {
            int warmBloodnessMeasureTemp;
            std::cout << "Введите меру теплокровности: "<<std::endl;
            std::cin >> warmBloodnessMeasureTemp;
            animals.push(new Mammals(name,warmBloodnessMeasureTemp));
            break;
        }
        case AnimalType::Artiodactyls: {
            int warmBloodnessMeasureTemp;
            int hoopQuntityTemp;
            std::cout << "Введите меру теплокровности: "<<std::endl;
            std::cin >> warmBloodnessMeasureTemp;
            std::cout << "Введите количество копыт: "<<std::endl;
            std::cin >> hoopQuntityTemp;
            animals.push(new Artiodactyls(name, warmBloodnessMeasureTemp, hoopQuntityTemp));
            break;
        }
        default:
            std::cout << "Такого типа нет" << std::endl;
    }
    std::cout <<'\n';
}
void Demo(MyStack<Animals*>& animals){

}

void Menu() {
    MyStack<Animals*> animals;
    int userChoice = 0;


    while (static_cast<Task>(userChoice) != Task::Exit) {
        std::cout << "Выберите номер, интересующего вас действия, и введите его в консоль для перехода\n";
        std::cout << "1. Добавить элемент в контейнер\n"
                  << "2. Печать содержимого контейнера\n"
                  << "3. Удалить элемент по индексу\n"
                  << "4. Очистить контейнер\n"
                  << "5. Деморежим\n"
                  << "6. Выход\n";

        std::cin >> userChoice;
        std::cout << std::endl;

        switch (static_cast<Task>(userChoice)) {
            case Task::Add:
                AddEl(animals);
                break;
            case Task::Print:
                print(animals);
                break;
            case Task::Delete: {
                int index;
                std::cout << "Введите индекс элемента для удаления: "<<std::endl;
                std::cin >> index;
                remove(animals, index);
                break;
            }
            case Task::Clear:
                clear(animals);
                break;
            case Task::Demo:
                Demo(animals);
                break;
            case Task::Exit:
                break;
            default:
                std::cout << "Неверный номер задания" << std::endl;
        }
    }
}
}
