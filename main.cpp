#include "fraction.hpp"

int main(int, char**) {
    FractionZone::Fraction f1("2/9");
    std::cout << f1<<std::endl;
    std::cout << "Введите дробь: \n";
    FractionZone::Fraction z;
    std::cin >> z;
    std::cout <<"z="<< z << std::endl;
    FractionZone::Fraction fr1(10, 14);
    FractionZone::Fraction fr2=1.25;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    FractionZone::Fraction fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    FractionZone::Fraction x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    FractionZone::Fraction f = dbl;
    std::cout << "f=" << f <<" "<<x<<" "<<z <<std::endl;
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f <<" "<<x<<" "<<dbl<< std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y +=  dbl+i + x;\
    std::cout << "y=" << y << std::endl;



    return 0;
}
