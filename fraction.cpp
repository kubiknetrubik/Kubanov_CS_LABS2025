#include "fraction.hpp"
namespace {
const int N_DEC = 10000;
}
namespace FractionZone {
Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}
Fraction::Fraction(int num, int den) {
    if (den == 0) {
        std::cout << "Invalid denumerator";
        return;
    }
    numerator = num;
    denominator = den;
    simplify();
}
Fraction::Fraction(Fraction& el) {
    numerator = el.numerator;
    denominator = el.denominator;
}
Fraction::Fraction(double db){
    denominator = N_DEC;
    numerator = static_cast<int>(db * denominator);
    simplify();
}
void Fraction::GetStr(const char* stroke) {
    int integer = 0;
    int num = 0;
    int den = 1;
    char* token;
    char buffer[50];
    std::strncpy(buffer, stroke, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    token = std::strtok(buffer, " ");
    if (token) {
        char* fractionPart = std::strchr(token, '/');
        if (fractionPart) {
            num = std::atoi(token);
            den = std::atoi(fractionPart + 1);
            numerator = num;
            if (den <= 0) {
                std::cout << "Invalid denominatorr";
                return;
            }
            denominator = den;
        } else {
            integer = std::atoi(token);
            token = std::strtok(nullptr, "/");
            if (token) {
                num = std::atoi(token);
                if (num < 0) {
                    std::cout << "Invalid numerator";
                    return;
                }
                token = std::strtok(nullptr, "\0");
                if (token) {
                    den = std::atoi(token);
                    if (den <= 0) {
                        std::cout << "Invalid denominatorr";
                        return;
                    }
                } else {
                    std::cout << "Invalid denominator";
                    return;
                }
                numerator = integer * den + (integer < 0 ? -num : num);
                denominator = den;

            } else {
                numerator = integer;
                denominator = den;
            }
        }
    } else {
        std::cout << "Invalid integer";
        return;
    }
    simplify();
}

Fraction::Fraction(char* stroke) {
    GetStr(stroke);
}

Fraction Fraction::operator+(Fraction& other) {
    return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}
Fraction Fraction::operator+(int other) {
    Fraction temp(other,1);

    return *this+temp;
}
Fraction Fraction::operator+(double other) {
    Fraction temp(other);
    return *this+temp;
}
Fraction operator+(double value,Fraction& frac){
    Fraction temp(value);
    return temp+frac;

}
Fraction operator+(int value, Fraction& frac){
    Fraction temp(value,1);
    return temp+frac;

}

Fraction& Fraction::operator+=(Fraction other) {
    *this=*this+other;
    return *this;
}
Fraction& Fraction::operator+=(int v) {
    Fraction temp(v,1);
    *this = *this + temp;
    return *this;
}
Fraction& Fraction::operator+=(double other) {
    Fraction temp(other);
    *this =*this+temp;
    return *this;
}

std::ostream& operator<<(std::ostream& out, Fraction& el) {
    int whole = el.numerator / el.denominator;
    int remainder = abs(el.numerator % el.denominator);
    if (el.denominator == 1) {
        out << el.numerator;
    } else if (whole != 0 && remainder != 0) {
        out << whole << " " << remainder << "/" << el.denominator;
    }else{
        out<<el.numerator<<"/"<<el.denominator;
    }
    return out;
}
std::istream& operator>>(std::istream& in, Fraction& el) {
    char buff[50];
    in.getline(buff, sizeof(buff));
    el.GetStr(buff);
    return in;
}

}  // namespace FractionZone
