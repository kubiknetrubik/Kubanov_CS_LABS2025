#include <iostream>
#include "mymath/mymath.hpp"
#include "mymat/mat.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 1+1=";
    std::cout << mymath::sum(10, 32) << std::endl;
    std::cout << mat::multiply(10, 32) << std::endl;


    return 0;
}
