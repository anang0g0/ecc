FLAGS = -lm -O3 -Wall -Wextra -Wpedantic

all:
	g++ -O2 ecc.cpp ntl.a

