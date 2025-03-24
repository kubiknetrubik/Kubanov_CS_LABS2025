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
        Polynomial polinom2;
        polinom2=polinom1;
        std::cout << "polinom2=polinom1 "<<polinom2<<std::endl;
        Polynomial polinom3;
        std::cout<<"Vvedite polinom3 "<<std::endl;
        std::cin>>polinom3;
        std::cout << "polinom3 "<<polinom3<<std::endl;
        polinom3*=polinom1;
        std::cout << "polinom3*=polinom1 "<<polinom3<<std::endl;
        polinom3+=polinom1;
        std::cout << "polinom3+=polinom1 "<<polinom3<<std::endl;
        polinom3.sort(true);
        std::cout << "polinom3 sorted vzrost "<<polinom3<<std::endl;
        polinom3.sort(false);
        std::cout << "polinom3 sorted ubiv "<<polinom3<<std::endl;








    } catch (...) {
        std::cout << "ERROR\n";
    }

    return 0;
}
