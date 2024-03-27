#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>
#include <docopt/docopt.h>

#include "easy_random.hpp"

using namespace std;
using namespace easy_std;

int main() {

    std::cout << randint(0, 10) << "\n";
    std::cout << random(0, 1) << "\n";

    std::vector<int> vec1 = {5, 8, 2, 99, 22, 45};
    std::cout << choice(vec1) << std::endl;

    shuffle_(vec1);
    for(int i = 0; i < vec1.size(); i++){
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
}