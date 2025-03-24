#pragma once
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
class Term{
private:
    int coef = 0;
    int degree=0;
public:
    Term();
    Term(int c);
    Term(int c, int d);
    friend Term operator+(const Term& a,const Term& b);
    friend std::ostream& operator<<(std::ostream& out, Term& el);
    friend std::istream& operator>>(std::istream& in, Term& el);
    friend class Polynomial;
    int getc();



};
