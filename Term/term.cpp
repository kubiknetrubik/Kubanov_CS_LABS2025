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
    char buffer[100]{};
    in.getline(buffer, 100);

    char* xCoords = strchr(buffer, 'x');

    if (xCoords) {
        *xCoords = '\0';

        if (*buffer == '\0' || strcmp(buffer, "+") == 0) {
            el.coef = 1;
        } else if (strcmp(buffer, "-") == 0) {
            el.coef = -1;
        } else {
            el.coef = atoi(buffer);
        }

        char* degPart = strchr(xCoords + 1, '^');
        if (degPart) {
            el.degree= atoi(degPart + 1);
        } else {
            el.degree = 1;
        }
    } else {
        el.coef = atoi(buffer);
        el.degree = 0;
    }

    return in;
}
int Term::getc(){
    return coef;

}
