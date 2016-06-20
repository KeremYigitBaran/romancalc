CFLAGS=-Wall -std=c99
LIBS=-lcheck

.PHONEY : all

.PHONEY : test

.PHONEY : clean

all: romancalc

romancalc: main.o romanmath.o
	gcc -o romancalc main.o romanmath.o

main.o: main.c romanmath.h
	gcc $(CFLAGS) -c main.c

romanmath.o: romanmath.c romanmath.h
	gcc $(CFLAGS) -c romanmath.c

test: romancalc-test
	CK_VERBOSITY="verbose" ./romancalc-test
	@echo "--------------"

romancalc-test: romanmath-test.o romanmath.o
	gcc -o romancalc-test romanmath.o romanmath-test.o $(LIBS)

romanmath-test.o: romanmath.o romanmath-test.c
	gcc $(CFLAGS) -Wno-sequence-point -c romanmath-test.c

clean:
	-rm romancalc romanmath.o main.o romancalc-test romanmath-test.o 
