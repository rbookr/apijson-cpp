#include "ServerGet2.h"

int main(){
    ServerGet2 server;

    server.get(
R"(
{
    "student" : {
        "id":3
    }
})"
    );
    return 0;
}
