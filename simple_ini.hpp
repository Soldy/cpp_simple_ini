#ifndef __CPP_SIMPLE_INI_HPP_
#define __CPP_SIMPLE_INI_HPP_
#include <algorithm> 
#include <cctype>
#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <map>


namespace simple_ini_tool{
struct ini_line {
    bool success ;
    std::string key;
    std::string value;
};

void ltrim(std::string &s) {
    s.erase(
      s.begin(),
      std::find_if(
        s.begin(),
        s.end(), 
        [](char c) {
            return !std::isspace(c);
        }
      )
    );
};

void rtrim(std::string &s) {
    s.erase(
      std::find_if(
        s.rbegin(), 
        s.rend(),
        [](char c) {
           return !std::isspace(c);
        }
      ).base(), 
      s.end()
    );
};

void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
};


ini_line splitter (std::string input_){
    ini_line out;
    out.success = false;
    for(int i = 0; input_.size() > i ; i++){
        if(out.success == true){
            out.value += input_[i];
        }else{
            if(input_[i] == '='){
                out.success = true;
            }else{
                out.key += input_[i];
            }
        }
    };
    trim(out.key);
    trim(out.value);
    return out;
};

std::map<std::string, std::string> read (std::string file_name){
    std::map<std::string, std::string> out;
    std::string line;
    ini_line one;
    std::ifstream ini_file;
    ini_file.open(file_name);
    while(getline(ini_file, line)) {
        one = splitter(line);
        if(one.success == true)
            out[one.key] = one.value;
    }
    return out;
}
}

#endif
