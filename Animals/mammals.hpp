#pragma once
#include "animals.hpp"
class Mammals: public Animals{
    protected:
        int warmBloodnessMeasure;
    public:
        Mammals(const char* name, int warmBloodnessMeasure);
        ~Mammals() override;
        void show() const override;

};
