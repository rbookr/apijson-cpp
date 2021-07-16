CXX=g++
CFLAGS=-lsqlite3

SRC=$(wildcard *.cpp)
TARGET=$(patsubst %.cpp,%,$(SRC))

all: $(TARGET)
	@echo done

% : %.cpp
	$(CXX) $(CFLAGS) -o $@.out $< 

clean:
	rm -rf $(TARGET)
