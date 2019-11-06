
CC=g++
CXXFLAGS=-std=c++11 -g

OBJS= Transition.o State.o Alphabet.o Dfa.o Nfa.o mainNFA2DFA.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o NFA2DFA ${OBJS}

clean:
	rm -rf *.o *.txt *.gv NFA2DFA
