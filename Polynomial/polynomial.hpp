#pragma once
#include <algorithm>
#include <sstream>
#include "../Term/term.hpp"
class Polynomial {
    Term* poly;
    int degree;
    int size;
    bool order_;

 public:
    Polynomial();
    Polynomial(int p);
    Polynomial(const Term& t);
    Polynomial(const Polynomial& p);
    ~Polynomial();
    Polynomial& operator=(const Polynomial& p);
    Polynomial& operator+=(const Polynomial& p);
    Polynomial& operator*=(const Polynomial& p);
    friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2);
    void sort(bool increase);
    friend std::ostream& operator<<(std::ostream& out, Polynomial& p);
    friend std::istream& operator>>(std::istream& in, Polynomial& p);
};
