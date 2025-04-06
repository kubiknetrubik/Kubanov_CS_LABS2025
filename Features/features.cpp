#include "features.hpp"
void clear(MyStack<Animals*>& animals){
    while (!animals.empty()) {
        Animals* ptr= animals.top_inf();
        delete ptr;
        animals.pop();
    }
}
