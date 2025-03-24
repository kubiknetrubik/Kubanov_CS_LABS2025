#include "term.hpp"
Term::Term() {
    coef = 0;
    degree = 0;
}
Term::Term(int c) {
    coef = c;
    degree = 0;
}
Term::Term(int c, int d) {
    coef = c;
    degree = d;
}

Term operator+(const Term& a, const Term& b) {
    if (a.degree != b.degree) {
        throw "INVALID";
    }
    return Term(a.coef + b.coef, a.degree);
}
std::ostream& operator<<(std::ostream& out, Term& el) {
    if (el.coef == 0) {
        return out;
    }
    if (el.degree == 0) {
        out << el.coef;
    } else {
        if (el.coef == 1) {
            out << "x";
        } else if (el.coef == -1) {
            out << "-x";
        } else {
            out << el.coef << "x";
        }
        if (el.degree != 1) {
            out << "^" << el.degree;
        }
    }
    return out;
}
std::istream& operator>>(std::istream& in, Term& el) {
    el.coef = 1;
    el.degree = 0;

    char ch;

    in >> el.coef;
    while (in.peek() == ' ') {
        in.ignore();
    }
    if (in.peek() == 'x') {

        in >> ch;
        el.degree = 1;
        while (in.peek() == ' ') {
            in.ignore();
        }
        if (in.peek() == '^') {
            in >> ch;
            in >> el.degree;
        }
    }
    return in;
}
