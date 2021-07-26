#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <variant>

#include "json.hpp"

using json = nlohmann::json;

class QueryConfig {
    using MAP_type = std::unordered_map<std::string, std::variant<int,std::string> >;
    public:
        QueryConfig() = default;
        QueryConfig(std::nullptr_t Nul) {}

        QueryConfig(const std::string &table) : table(table) {}
        QueryConfig(const MAP_type & _map) : where(_map){}

        std::string getTable();
        std::vector<std::string> getColumns();

        QueryConfig & setColumns(const std::vector<std::string> & columns){
            this->columns.clear();
            for (const auto& e : columns) {
                this->columns.push_back(e);
            }
            return *this;
        }

        static QueryConfig getQueryConfig(std::string table , json request){
            MAP_type transferredRequest;
            for( auto& el : request.items()){
                //keys.push_back(el.key());
                auto & key = el.key();
                auto & val = el.value();
                std::cout << key << " --<";
                std::cout << val<< std::endl;
                if( val.is_string()){
                    transferredRequest[key] = val.get<std::string>();
                }
                else if(val.is_number_integer()) {
                    transferredRequest[key] = val.get<int>();
                }
            }
            return QueryConfig(transferredRequest);
        }

    private:
        std::string table;
        std::vector<std::string> columns;
        std::vector<std::vector<std::string >> values;
        MAP_type where; // TODO key2 is not Object
        int limit;
        int page;
        int position;


};
