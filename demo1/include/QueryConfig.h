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

    private:
        std::string table;          //要查询的表名
        std::vector<std::string> columns; // 列名 数组
        std::vector<std::vector<std::string >> values;  //
        MAP_type where; 
        int limit;
        int page;
        int position;

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

        static QueryConfig getQueryConfig(std::string table , json request);
        static std::string getWhereString(MAP_type where);

};
