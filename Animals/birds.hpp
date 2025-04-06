#pragma once
#include "animals.hpp"
class Birds: public Animals{
    protected:
        int wings;
    public:
        Birds(const char* name, int wings);
        ~Birds() override;
        void show() const override;

};
