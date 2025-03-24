#include "Polynomial/polynomial.hpp"
#include "Term/term.hpp"

int main() {
    try {
        Term term1;
        std::cout<<"Vvedite Term1 "<<std::endl;
        std::cin >> term1;
        std::cout << "Term1 "<<term1<<std::endl;
        Term term2;
        std::cout<<"Vvedite Term2 "<<std::endl;
        std::cin >> term2;
        std::cout << "Term2 "<<term2<<std::endl;
        Term temp;
        temp=term1+term2;
        std::cout<<"Summa "<<temp<<std::endl;
        Polynomial polinom1;
        std::cout<<"Vvedite polinom1 "<<std::endl;
        std::cin>>polinom1;
        std::cout << "polinom1 "<<polinom1<<std::endl;


    } catch (...) {
        std::cout << "ERROR\n";
    }

    return 0;
}
