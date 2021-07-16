g++ -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0 -I../lib/mysql/include -L../lib/mysql/lib64 mysql.cpp -o mysql  -lmysqlcppconn8 
