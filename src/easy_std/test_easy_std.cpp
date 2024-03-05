/*

*/


# include <iostream>
# include <vector>


std::string input(const std::string& msg) {
    std::cout << msg;
    std::string str;
    getline(std::cin, str);
    return str;
}


int main() {

    std::cout << "\n***** INPUT *****\n";
    std::string name1 = input("Como se chama? ");
    std::cout << "Nome: " << name1 << std::endl;


    std::vector<int> vals {10, 72, -500};
    for (const auto& val : vals) {
        std::cout << val << std::endl;
    }  

    return 0;
}