CXX=g++
CXXFLAGS=-Wall -W -Werror -pedantic -O3 -march=native -std=c++11

BIN=shufflecards
SRC=src/main.cpp src/CardDeck.cpp
OBJ=$(SRC:.cpp=.o)

.PHONY: all $(BIN)

default: all

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(BIN)

%.o:%.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

test: $(BIN)
	@echo "Test for 100 cards:"
	@./$(BIN) 100
	@echo "Test for 200 cards:"
	@./$(BIN) 200
	@echo "Test for 300 cards:"
	@./$(BIN) 300
	@echo "Test for 313 cards:"
	@./$(BIN) 313

clean:
	rm -f $(OBJ)

distclean: clean
	rm -f $(BIN)
