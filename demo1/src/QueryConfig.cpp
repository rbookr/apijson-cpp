#include "QueryConfig.h"

#include <set>
#include <vector>


std::string  QueryConfig::getWhereString(const MAP_type &where){
    if( where.size() > 0){
        std::string whereString = " where ";
        for (const auto&[key,value] : where) {
            if( auto pval = std::get_if<int>(&value) ){
                whereString += ( key + "=" + std::to_string(*pval));
            }
            else { //string
                whereString += ( key + "=" + std::get<std::string>(value));
            }
            whereString += " &";
        }

        while (whereString.back() == '&' || whereString.back() ==' '  ) {
            whereString.pop_back();
        }

        const auto ends_with = [](std::string const & value, std::string const & ending) {
            if (ending.size() > value.size()) return false;
            return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
        };

        if(!ends_with(whereString, "where"))
            return whereString;
    }
    return "";
}

QueryConfig QueryConfig::getQueryConfig(std::string table , json request){
    MAP_type transferredRequest;
    for( auto& el : request.items()){
        //keys.push_back(el.key());
        auto & key = el.key();
        auto & val = el.value();
        //std::cout << key << " --<";
        //std::cout << val<< std::endl;
        debug_out(TAG,"  getQueryConfig :","key ",key ," <=> value:",val);
        if( val.is_string()){
            transferredRequest[key] = val.get<std::string>();
        }
        else if(val.is_number_integer()) {
            transferredRequest[key] = val.get<int>();
        }
    }
    return QueryConfig(transferredRequest);
}

