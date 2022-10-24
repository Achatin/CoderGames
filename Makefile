CXX = gcc
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c11 -g

SRC = cg.c
OBJ = $(SRC:.cc=.o)
EXEC = cg

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)