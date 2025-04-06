#pragma once
#include <iostream>
#include "Features/features.hpp"
#include "MyStack/MyStack.hpp"
#include "Animals/animals.hpp"
#include "Animals/birds.hpp"
#include "Animals/mammals.hpp"
#include "Animals/artiodactyls.hpp"
namespace StartApp{
enum class Task {
    Add = 1,
    Print = 2,
    Delete = 3,
    Clear = 4,
    Demo = 5,
    Exit = 6
};
enum class AnimalType {
    Birds = 1,
    Mammals = 2,
    Artiodactyls= 3
};
void Menu();
void AddEl(MyStack<Animals*>& animals);
void Demo(MyStack<Animals*>& animals);
}
