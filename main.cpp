#include "MyStack/MyStack.hpp"

int main(int, char**) {
    try {
        int N{};
        std::cout<<"Введите целое число N:"<<std::endl;
        std::cin>>N;
        if (N <= 0) {
            throw std::runtime_error("Число N не валидно.");
        }
        MyStack<int> stack;
        Multipliers(N,stack);
        MyStack<int> stack2=stack;
        Print(stack,N,false);
        Print(stack2,N,true);


    } catch (std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
