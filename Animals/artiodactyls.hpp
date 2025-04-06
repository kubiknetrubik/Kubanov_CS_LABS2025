#pragma once
#include "mammals.hpp"
class Artiodactyls: public Mammals{
    protected:
        int hoopQuntity;
    public:
        Artiodactyls(const char* name, int warmBloodnessMeasure,int hoopQuntity);
        ~Artiodactyls() override;
        void show() const override;

};
