#include <cstdio>
#include <sqlite3.h>

int main(){
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("test.db", &db);

    sqlite3_close(db);
    return 0;
}
