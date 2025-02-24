#pragma once
#include <cstring>
#include <iostream>
#include <cstdlib>
namespace FractionZone{
class Fraction{
    private:
        int numerator;
        int denominator;
        int gcd(int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
        void simplify() {
            int divisor = gcd(numerator, denominator);
            numerator /= divisor;
            denominator /= divisor;
            if (denominator < 0) {
                numerator = -numerator;
                denominator = -denominator;
            }
        }
    public:
        Fraction();
        Fraction(int num, int den);
        Fraction(char* stroke);
        Fraction(double db);
        Fraction(Fraction& el);

        void GetStr(const char* stroke);

        Fraction operator+(Fraction& other);
        Fraction operator+(int other);
        Fraction operator+(double other);
        friend Fraction operator+(double value,Fraction& frac);
        friend Fraction operator+(int value,Fraction& frac);

        Fraction& operator+=(Fraction other);
        Fraction& operator+=(int v);
        Fraction& operator+=(double other);


        friend std::ostream& operator<<(std::ostream& out, Fraction& el);
        friend std::istream& operator>>(std::istream& in, Fraction& el);




};
}
