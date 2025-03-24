#include "polynomial.hpp"
Polynomial::Polynomial(){
    poly=nullptr;
    degree=0;
    size=0;
    order_=true;
}
Polynomial::Polynomial(int p){
    degree=0;
    size=1;
    order_=true;
    poly = new Term[1];
    poly[0] = Term(p, 0);
}
Polynomial::Polynomial(const Term& t) {
    degree=t.degree;
    size=1;
    order_=true;
    poly = new Term[1];
    poly[0] = t;
}
Polynomial::Polynomial(const Polynomial& p) {
    degree = p.degree;
    size = p.size;
    order_ = p.order_;

    poly = new Term[size];

    for (int i = 0; i < size; ++i) {
        poly[i] = p.poly[i];
    }
}
Polynomial::~Polynomial() {
    delete[] poly;
}

Polynomial& Polynomial::operator=(const Polynomial& p) {
    if (this == &p)
        return *this;

    delete[] poly;
    size = p.size;
    degree = p.degree;
    poly = new Term[size];
    for (int i = 0; i < size; i++) {
        poly[i] = p.poly[i];
    }
    return *this;
}
Polynomial& Polynomial::operator+=(const Polynomial& p) {
    for (int i = 0; i < p.size; ++i) {
        bool found = false;
        for (int j = 0; j < size; ++j) {
            if (poly[j].degree == p.poly[i].degree) {
                poly[j] = poly[j] + p.poly[i];
                found = true;
                break;
            }
        }
        if (!found) {
            Term* newPoly = new Term[size + 1];
            for (int j = 0; j < size; ++j) {
                newPoly[j] = poly[j];
            }
            newPoly[size] = p.poly[i];

            delete[] poly;
            poly = newPoly;
            ++size;
        }
    }
    degree = std::max(degree, p.degree);
    return *this;
}
Polynomial& Polynomial::operator*=(const Polynomial& p) {
    Polynomial result;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < p.size; ++j) {
            result += Polynomial(Term(poly[i].coef * p.poly[j].coef,poly[i].degree * p.poly[j].degree));
        }
    }

    *this = result;
    return *this;
}
Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result = p1;
    result += p2;
    return result;
}

Polynomial operator*(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result = p1;
    result *= p2;
    return result;
}

void Polynomial::sort(bool increase) {
    order_ = increase;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if ((increase && poly[j].degree > poly[j + 1].degree) || (!increase && poly[j].degree < poly[j + 1].degree)) {
                std::swap(poly[j], poly[j + 1]);
            }
        }
    }
}

std::ostream& operator<<(std::ostream& out, Polynomial& p) {
    if (p.size == 0) {
        return out << 0;
    }


    for (int i = 0; i < p.size; ++i) {
        out<<p.poly[i]<<" ";
    }

    return out;
}
std::istream& operator>>(std::istream& in, Polynomial& p) {
    delete[] p.poly;
    p.poly = nullptr;
    p.size = 0;
    p.degree = 0;
    Term x;
    in>>x;
    std::cout<<x<<std::endl;
    p+=Polynomial(x);




    return in;
}
