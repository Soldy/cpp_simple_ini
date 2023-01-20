#include "simple_ini.hpp"
#include <string>
#include <map>


int main(){
    std::map<std::string, std::string> ini = simple_ini_tool::read("example.ini");
    for(auto const & [k, v] : ini){
        std::cout << k << " = " << v << std::endl;
    }
    return 0;
}

