#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class QueryConfig {
    using MAP_type = std::unordered_map<std::string, std::string>;
    public:
        QueryConfig() = default;
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

    private:
        std::string table;
        std::vector<std::string> columns;
        std::vector<std::vector<std::string >> values;
        MAP_type where; // TODO key2 is not Object
        int limit;
        int page;
        int position;


};
