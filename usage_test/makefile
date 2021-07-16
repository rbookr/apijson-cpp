CXX=g++
CFLAGS=-I../lib/mysql/include -L../lib/mysql/lib64 -lmysqlcppconn8  -lssl -lcrypto -lmysqlcppconn

SRC=$(wildcard *.cpp)
TARGET=$(patsubst %.cpp,%,$(SRC))

all: $(TARGET)
	@echo done

% : %.cpp
	$(CXX) $(CFLAGS) -o $@ $< 

clean:
	rm -rf $(TARGET)
