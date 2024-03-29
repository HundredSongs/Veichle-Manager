#include <iostream>
#include <vector>

#include "easy_random.hpp"

using namespace std;
using namespace easy_std;

int main() {

    std::cout << randint(0, 10) << "\n";
    std::cout << random(0, 1) << "\n";

    std::vector<int> vec1 = {5, 8, 2, 99, 22, 45};
    std::cout << choice(vec1) << std::endl;
    /////////////////////////////////////
    shuffle_(vec1);

    for(int i = 0; i < vec1.size(); i++){
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    //////////////////////////////////////
    auto vec2 = sample(vec1, 3);
    
    for(int i = 0; i < vec2.size(); i++){
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;
    ///////////////////////////////////////
    std::vector<std::string> vec3 = {"one", "two", "three", "four", "five"};

    auto vec4 = sample(vec3, 3);
    
    for(int i = 0; i < vec4.size(); i++){
        std::cout << vec4[i] << " ";
    }
    std::cout << std::endl;

}