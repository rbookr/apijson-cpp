#pragma once
#include <string>
#include <iostream>

bool isNumber(std::string name);

template<typename... Args>
void debug_out(Args&&... args){
    (std::cout << ... << args) <<std::endl;
}
