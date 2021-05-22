RM = erase
CC = g++
FLAGS = -std=c++11 -Wall

TARGET = chess.exe
SOURCE = src

SRC_H = $(wildcard $(SOURCE)/*.h)
SRC_CPP = $(wildcard $(SOURCE)/*.cpp)
SRC_OBJ = $(SRC_CPP:%.cpp=%.o)

$(SOURCE)/%.o: $(SOURCE)/%.cpp $(SRC_H)
	$(CXX) $(CFLAGS) $(DEFINES) -c $< -o $@

all : $(TARGET)

rebuild : clean all

$(TARGET) : $(SRC_OBJ)
	$(CC) $(FLAGS) $(DEFINES) $(SRC_OBJ) -o $@

deploy: 
	git add .
	git commit -m "Initial commit"
	git push origin main

clean :
	$(RM) $(SOURCE)\*.o
	$(RM) $(TARGET)

.PHONY : all rebuild clean deploy 