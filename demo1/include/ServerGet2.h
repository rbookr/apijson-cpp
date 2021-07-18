#pragma once
#include "QueryConfig.h"
#include "json.hpp"

using json = nlohmann::json;

class ServerGet2 {
    public:
        static const std::string TAG;
    private:
        const std::string SEPARATOR = "/";
};

const std::string ServerGet2::TAG = "ServerGet2";
