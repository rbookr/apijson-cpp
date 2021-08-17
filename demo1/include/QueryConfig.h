#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <variant>

#include "utils.h"
#include "json.hpp"

using json = nlohmann::json;

class QueryConfig {

    static const constexpr std::string_view TAG = "QueryConfig";

    using MAP_type = std::unordered_map<std::string, std::variant<int,std::string> >;

    private:
        std::string table;          //要查询的表名
        std::vector<std::string> columns; // 列名 数组
        std::vector<std::vector<std::string >> values;  //
        MAP_type where; 
        int limit{0};
        int page{0};
        int position{0};

    public:
        QueryConfig() = default;
        QueryConfig(std::nullptr_t Nul) {}

        QueryConfig(const std::string &table) : table(table) {}
        QueryConfig(const MAP_type & _map) : where(_map){}

        //std::string getTable();
        std::vector<std::string> getColumns();

        QueryConfig & setColumns(const std::vector<std::string> & columns){
            this->columns.clear();
            for (const auto& e : columns) {
                this->columns.push_back(e);
            }
            return *this;
        }

        std::string getTable() const { return table;}

        static QueryConfig getQueryConfig(std::string table , json request);
        static std::string getWhereString(const MAP_type &where);

        std::string getWhereString() const {
            return getWhereString(where);
        }

        std::string getLimit() const{
            return limit <=0 ? "" : " limit "+std::to_string(limit);
        }

        static std::string getSQL(QueryConfig const * config_ptr){
            return config_ptr == nullptr ? "": 
                std::string("select * from ")
                + config_ptr->getTable()
                + config_ptr->getWhereString()
                + config_ptr->getLimit();
        }

};
