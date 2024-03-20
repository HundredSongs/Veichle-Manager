#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <vector>
#include <string>
#include <regex>

#include <fmt/format.h>
#include <fmt/ranges.h>

#include <boost/algorithm/string.hpp>

namespace utils {
    inline vector<std::string> split(
        const std::string& str, 
        const std::string& delim
    ) {
        std::vector<std::string> results;
        boost::iter_split(results, str, boost::first_finder(delim));
        return results;
    }

    template<typename T>
    std::string join(
            const vector<T>& elems, 
            const std::string& sep = std::string(" ")
    ) {
        std::ostringstream ss;
        if (elems.size() > 0) {
            ss << elems[0];
            for (auto i = 1; i < elems.size(); i += 1) {
                ss << sep << elems[i];
            }
        }
        return ss.str();
    }

    inline string trim(string& str) {
        boost::trim(str);
        return str;
    }

    inline string trim_copy(const string& str) {
        auto str2(str);
        boost::trim(str2);
        return str2;
    }

    inline bool is_alpha(const string& str) {
        return std::regex_match(str, std::regex("^[A-Za-z]+$"));
    }

    inline bool is_digit(const string& str) {
        return std::regex_match(str, std::regex("^[0-9]+$"));
    }

    inline bool is_alnum(const string& str) {
        return std::regex_match(str, std::regex("^[A-Za-z0-9]+$"));
    }

    inline string to_upper_copy(const string& str) {
        auto str2(str);
        for (auto& ch : str2) {
            if (ch >= 'a' && ch <= 'z') {
                ch -= 32;
            }
        }
        return str2;
    }

    inline void _test() {
        #include <iostream>
        #include <fmt/format.h>
        #include <fmt/ranges.h>

        using namespace std;

        vector<string> elems1;
        vector<string> elems2{"alberto"};
        vector<string> elems3{"alberto", "armando", "augusto"};

        print("\n");
        cout << "utils::join(elems1) -> "       << utils::join(elems1) << endl;
        cout << "utils::join(elems1, ', ') -> " << utils::join(elems1, ", ") << endl;
        cout << "utils::join(elems2) -> "       << utils::join(elems2) << endl;
        cout << "utils::join(elems2, ', ') -> " << utils::join(elems2, ", ") << endl;
        cout << "utils::join(elems3) -> "       << utils::join(elems3) << endl;
        cout << "utils::join(elems3, ', ') -> " << utils::join(elems3, ", ") << endl;

        string str1 = "";
        string str2 = "alberto";
        string str3 = "alberto, armando, augusto";

        print("\n");
        cout << "utils::split(str1, ', ') -> "; print("|{}|\n", utils::split(str1, ", "));
        cout << "utils::split(str2, ', ') -> "; print("{}\n", utils::split(str2, ", "));
        cout << "utils::split(str3, ', ') -> "; print("{}\n", utils::split(str3, ", "));

        string str4 = "";
        string str5 = " ";
        string str6 = "alberto";
        string str7 = " alberto";
        string str8 = "alberto ";
        string str9 = "alberto ";
        string str10 = "    alberto    ";

        print("\n");
        print("utils::trim(\"{}\") -> |{}|\n", str4, utils::trim_copy(str4));
        print("utils::trim(\"{}\") -> |{}|\n", str5, utils::trim_copy(str5));
        print("utils::trim(\"{}\") -> |{}|\n", str6, utils::trim_copy(str6));
        print("utils::trim(\"{}\") -> |{}|\n", str7, utils::trim_copy(str7));
        print("utils::trim(\"{}\") -> |{}|\n", str8, utils::trim_copy(str8));
        print("utils::trim(\"{}\") -> |{}|\n", str9, utils::trim_copy(str9));
        print("utils::trim(\"{}\") -> |{}|\n", str10, utils::trim_copy(str10));

        string str11 = ""; 
        string str12 = " "; 
        string str13 = "$#$#123"; 
        string str14 = "abc1"; 
        string str15 = "1abc"; 
        string str16 = "abc"; 
        string str17 = "1234"; 
        string str18 = "1234.23"; 

        print("\n");
        print("utils::is_alpha(\"{}\") -> {}\n", str11, utils::is_alpha(str11));
        print("utils::is_alpha(\"{}\") -> {}\n", str12, utils::is_alpha(str12));
        print("utils::is_alpha(\"{}\") -> {}\n", str13, utils::is_alpha(str13));
        print("utils::is_alpha(\"{}\") -> {}\n", str14, utils::is_alpha(str14));
        print("utils::is_alpha(\"{}\") -> {}\n", str15, utils::is_alpha(str15));
        print("utils::is_alpha(\"{}\") -> {}\n", str17, utils::is_alpha(str17));
        print("utils::is_alpha(\"{}\") -> {}\n", str18, utils::is_alpha(str18));
        print("utils::is_alpha(\"{}\") -> {}\n", str16, utils::is_alpha(str16));

        print("\n");
        print("utils::is_digit(\"{}\") -> {}\n", str11, utils::is_digit(str11));
        print("utils::is_digit(\"{}\") -> {}\n", str12, utils::is_digit(str12));
        print("utils::is_digit(\"{}\") -> {}\n", str13, utils::is_digit(str13));
        print("utils::is_digit(\"{}\") -> {}\n", str14, utils::is_digit(str14));
        print("utils::is_digit(\"{}\") -> {}\n", str15, utils::is_digit(str15));
        print("utils::is_digit(\"{}\") -> {}\n", str16, utils::is_digit(str16));
        print("utils::is_digit(\"{}\") -> {}\n", str18, utils::is_digit(str18));
        print("utils::is_digit(\"{}\") -> {}\n", str17, utils::is_digit(str17));

        print("\n");
        print("utils::is_alnum(\"{}\") -> {}\n", str11, utils::is_alnum(str11));
        print("utils::is_alnum(\"{}\") -> {}\n", str12, utils::is_alnum(str12));
        print("utils::is_alnum(\"{}\") -> {}\n", str13, utils::is_alnum(str13));
        print("utils::is_alnum(\"{}\") -> {}\n", str18, utils::is_alnum(str18));
        print("utils::is_alnum(\"{}\") -> {}\n", str14, utils::is_alnum(str14));
        print("utils::is_alnum(\"{}\") -> {}\n", str15, utils::is_alnum(str15));
        print("utils::is_alnum(\"{}\") -> {}\n", str16, utils::is_alnum(str16));
        print("utils::is_alnum(\"{}\") -> {}\n", str17, utils::is_digit(str17));

        print("\n");
        print("utils::to_upper_copy(\"{}\") -> {}\n", str14, utils::to_upper_copy(str14));
    }
}

#endif    print("utils::is_digit(\"{}\") -> {}\n", str13, utils::is_digit(str13));
        print("utils::is_digit(\"{}\") -> {}\n", str14, utils::is_digit(str14));
        print("utils::is_digit(\"{}\") -> {}\n", str15, utils::is_digit(str15));
        print("utils::is_digit(\"{}\") -> {}\n", str16, utils::is_digit(str16));
        print("utils::is_digit(\"{}\") -> {}\n", str18, utils::is_digit(str18));
        print("utils::is_digit(\"{}\") -> {}\n", str17, utils::is_digit(str17));

        print("\n");
        print("utils::is_alnum(\"{}\") -> {}\n", str11, utils::is_alnum(str11));
        print("utils::is_alnum(\"{}\") -> {}\n", str12, utils::is_alnum(str12));
        print("utils::is_alnum(\"{}\") -> {}\n", str13, utils::is_alnum(str13));
        print("utils::is_alnum(\"{}\") -> {}\n", str18, utils::is_alnum(str18));
        print("utils::is_alnum(\"{}\") -> {}\n", str14, utils::is_alnum(str14));
        print("utils::is_alnum(\"{}\") -> {}\n", str15, utils::is_alnum(str15));
        print("utils::is_alnum(\"{}\") -> {}\n", str16, utils::is_alnum(str16));
        print("utils::is_alnum(\"{}\") -> {}\n", str17, utils::is_digit(str17));

        print("\n");
        print("utils::to_upper_copy(\"{}\") -> {}\n", str14, utils::to_upper_copy(str14));
    }
}

#endif