#pragma once
#include <cstring>
#include <iostream>
class Animals{
    protected:
        char* name;
    public:
        Animals(const char* name);
        virtual ~Animals();
        virtual void show() const = 0;
};
