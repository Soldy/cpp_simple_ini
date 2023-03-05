#include "subs/trim/just_trim.hpp"
#include "simple_ini.hpp"
#include <string>
#include <map>
#include <iostream>


int main(){
    try{
        std::map<std::string, std::string> ini = simple_ini_tool::read("example.ini");
        for(auto const & [k, v] : ini){
            std::cout << k << " = " << v << std::endl;
        }
    }catch (const std::ios_base::failure& e) { 
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}

