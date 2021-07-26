#include "utils.h"

bool isNumber(std::string name){
    if( name.length() == 0) return 0;

    for (const auto& e : name) {
        if(!std::isdigit(e))
            return 0;
    }
    return 1;
}
