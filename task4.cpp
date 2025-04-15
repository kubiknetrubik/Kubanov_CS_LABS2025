#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <random>
//variant 5
void print(std::vector<bool> vector) {
    for(int i = 0;i<vector.size();++i){
        std::cout<<vector[i]<<' ';
    }
    std::cout << std::endl;
}

bool randomNum() {
    std::random_device r{};
    std::default_random_engine randomEngine(r());
    std::uniform_int_distribution distribution(0, 1);
    return distribution(randomEngine);
}

int main() {
    std::vector<bool> vector;
    for (int i = 0; i < 20; ++i) {
        vector.push_back(randomNum());
    }
    print(vector);
    int counterTrue = std::count(vector.begin(), vector.end(), true);
    int counterFalse = std::count(vector.begin(), vector.end(), false);
    std::cout << "True: " << counterTrue << " False: " << counterFalse << std::endl;
    vector.erase(vector.begin(), vector.begin() + 10);
    print(vector);

    return 0;
}
