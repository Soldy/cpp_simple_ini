#include "simple_ini.hpp"
#include <string>
#include <map>


int main(){
    std::map<std::string, std::string> ini = simple_ini_tool::read("example.ini");
    std::cout << "test_string = " << ini["test_string"] << std::endl;
    std::cout << "test_number = " << ini["test_number"] << std::endl;
    return 0;
}

