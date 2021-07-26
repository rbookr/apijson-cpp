#pragma once
#include <iostream>

#include "QueryConfig.h"
#include "utils.h"

#include "json.hpp"

using json = nlohmann::json;

class ServerGet2 {
    public:
        static const std::string TAG;
        const std::string SEPARATOR = "/";


        json get(std::string json_str){
            auto ret = json::parse(json_str);
            std::cout << ret << std::endl;

            parseRelation = false;
            auto res = getObject("" , nullptr, "", ret);

            std::cout << res << std::endl;
            return ret;
        }

    private:
        json getObject(
                std::string parentPath,
                QueryConfig parentConfig,
                std::string name,
                json request
                );

        QueryConfig getQueryConfig(std::string table,json request);
        
        json getSQLObject(QueryConfig config);


        std::string getPath(std::string parentPath,std::string name){
            if( parentPath.length() == 0)
                return name;
            else 
                return parentPath + SEPARATOR + name;
        }

        bool isArrayKey(std::string key){
            return key.length() >=2 && key.back() == ']' && key[key.length()-2] == '[' ;
        }
        bool isObjectKey(std::string key){
            if( key.length() == 0) return 0;
            auto a = !isArrayKey(key) && !isNumber(key);
            //debug_out("isObjectKey ",a," !isA ",!isArrayKey(key)," !isNum " ,!isNumber(key));
            return a;
        }

        

        bool parseRelation;
};

