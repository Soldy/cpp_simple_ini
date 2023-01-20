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
    bool success = false;
    std::string key;
    std::string value;
};

bool spaceCheck(char c){
    return !std::isspace(c);
};

void leftTrim(std::string &input_) {
    input_.erase(
      input_.begin(),
      std::find_if(
        input_.begin(),
        input_.end(), 
        spaceCheck
      )
    );
};

void rightTrim(std::string &input_) {
    input_.erase(
      std::find_if(
        input_.rbegin(), 
        input_.rend(),
        spaceCheck
      ).base(), 
      input_.end()
    );
};

void trim(std::string &input_) {
    rightTrim(input_);
    leftTrim(input_);
};

ini_line splitter (std::string &input_){
    ini_line out;
    int size = input_.size();
    if(
      1 > size         ||
      input_[0] == '=' ||
      input_[0] == '#' ||
      input_[0] == '['
    )
         return out;
    int i;
    for(i = 0; size > i ; i++)
        if(input_[i] == '=')
           break;
    if (i != size){
        out.key = input_.substr(0,i-1);
        out.value = input_.substr(i+1,size);
        trim(out.key);
        trim(out.value);
        out.success = true;
    }
    return out;
};

std::map<std::string, std::string> read (std::string file_name){
    std::map<std::string, std::string> out;
    std::string line;
    ini_line one;
    std::ifstream ini_file;
    ini_file.open(file_name);
    while(getline(ini_file, line)){
        one = splitter(line);
        if(one.success == true)
            out[one.key] = one.value;
    }
    return out;
};
}

#endif
