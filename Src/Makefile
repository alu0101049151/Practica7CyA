
CC=g++
CXXFLAGS=-std=c++11 -g

OBJS= Transition.o State.o Alphabet.o Dfa.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o NFA2DFA ${OBJS}

clean:
	rm -rf *.o *.txt *.gv NFA2DFA
