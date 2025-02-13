#pragma once
namespace ClassDoer {
enum class Command {
    Read = 1,
    Write = 2,
    Sort= 3,
    Add = 4,
    Delete= 5,
    Print = 6,
    Exit = 7
};


void ExecuteMenu();
}  // namespace ClassDoer
