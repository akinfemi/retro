LDFLAGS=-lncurses

all:
	clang++ -Wall -Werror -Wextra $(LDFLAGS) *.cpp

