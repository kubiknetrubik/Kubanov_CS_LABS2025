#include "StartApp.hpp"
typedef ListNode<Animals*, MyStack<Animals*>> Node;
namespace StartApp{
void Clear(MyStack<Animals*>& animals){
    while (!animals.empty()) {
        Animals* ptr= animals.top_inf();
        delete ptr;
        animals.pop();
    }
}
void Print(MyStack<Animals*>& animals){
    if (animals.empty()) {
        std::cout << "Стек пустой." << std::endl;
        return;
    }
    int i = 0;
    std::cout << "Содержимое стека:" << std::endl;
    Node* ptr = animals.GetTop();
    std::cout << i++ << ") ";
    ((ptr->GetD()))->show();
    ptr=ptr->GetNext();

    while (ptr) {
        std::cout << i++ << ") ";
        ((ptr->GetD()))->show();
        ptr=ptr->GetNext();
    }



}
void Remove(MyStack<Animals*>& animals, int index){
    if (animals.empty()) {
        std::cout << "Пустой" << std::endl;
    }
    Node* ptr = animals.GetTop();
    Node* prev= animals.GetTop();
    int i=0;
    while(ptr){
        if(i==index){

            if(ptr->GetNext()){
                if(i==0){
                    animals.SetTop(ptr->GetNext());
                }else{
                    prev->SetNext(ptr->GetNext());
                }

            }else{
                prev->SetNext(nullptr);

            }


            if (i==0&&!(ptr->GetNext())){
                animals.SetTop(nullptr);
            }
            delete ptr->GetD();
            delete ptr;
            break;

        }
        ++i;
        prev=ptr;
        ptr=ptr->GetNext();

    }
    if(!ptr){
        std::cout<<"Такого индекса нет"<<std::endl;

    }



}
void AddEl(MyStack<Animals*>& animals) {

    int type;
    std::cout << "Выберите вид животного:" << std::endl;
    std::cout << "1. Птица" << std::endl;
    std::cout << "2. Млекопитающее" << std::endl;
    std::cout << "3. Парнокопытное" << std::endl;
    std::cin >> type;
    char name[100];
    std::cout << "Введите имя животного: "<< std::endl;
    std::cin.ignore();
    std::cin.getline(name, 100);

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
    animals.push(new Birds("Сокол",2));
    animals.push(new Mammals("Кот", 50));
    animals.push(new Artiodactyls("Лошадь", 20, 4));
    Print(animals);

    std::cout << "Удаление второго элемента:" << std::endl;
    Remove(animals, 2);
    Print(animals);
    std::cout << "Очистка контейнера с животными:" << std::endl;
    Clear(animals);
    Print(animals);
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
                Print(animals);
                break;
            case Task::Delete: {
                int index;
                std::cout << "Введите индекс элемента для удаления: "<<std::endl;
                std::cin >> index;
                Remove(animals, index);
                break;
            }
            case Task::Clear:
                Clear(animals);
                break;
            case Task::Demo:
                Demo(animals);
                break;
            case Task::Exit:
                Clear(animals);
                break;
            default:
                std::cout << "Неверный номер задания" << std::endl;
                break;
        }
    }
}
}
