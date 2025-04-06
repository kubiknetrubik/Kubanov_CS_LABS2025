#include "features.hpp"
void clear(MyStack<Animals*>& animals){
    while (!animals.empty()) {
        Animals* ptr= animals.top_inf();
        delete ptr;
        animals.pop();
    }
}
void print(MyStack<Animals*>& animals) {
    if (animals.empty()) {
        std::cout << "Стек пустой." << std::endl;
        return;
    }

    MyStack<Animals*> animalsTemp;
    std::cout << "Содержимое стека:" << std::endl;
    int i{};
    while (!animals.empty()) {
        Animals* ptr = animals.top_inf();
        std::cout << i++ << ") ";
        ptr->show();
        animalsTemp.push(ptr);
        animals.pop();
    }

    while (!animalsTemp.empty()) {
        animals.push(animalsTemp.top_inf());
        animalsTemp.pop();
    }

    std::cout << std::endl;
}

bool remove(MyStack<Animals*>& animals, int index) {
    if (animals.empty()) {
        return false;
    }

    MyStack<Animals*> animalsTemp;
    int currentIndex = 0;

    while (!animals.empty()) {
        if (currentIndex == index) {
            Animals* ptr = animals.top_inf();
            delete ptr;
            animals.pop();
            ++currentIndex;
            continue;
        }

        Animals* ptr = animals.top_inf();
        animalsTemp.push(ptr);
        animals.pop();
        ++currentIndex;
    }

    while (!animalsTemp.empty()) {
        animals.push(animalsTemp.top_inf());
        animalsTemp.pop();
    }

    return true;
}
