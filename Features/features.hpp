#pragma once

#include "../Animals/animals.hpp"
#include "../MyStack/MyStack.hpp"
void print(MyStack<Animals*>& animals);
bool remove(MyStack<Animals*>& animals, int index);
void clear(MyStack<Animals*>& animals);
