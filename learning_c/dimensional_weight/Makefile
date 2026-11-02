CC      = gcc
UNITY   = ../../vendor/unity
CFLAGS  = -Wall -Wextra -std=c11 -I. -I$(UNITY)

PROG    = dweight
MAIN    = dweight.c
SRC     = dweight_calc.c
TEST    = test_dweight_calc

all: $(PROG)

$(PROG): $(MAIN) $(SRC) dweight.h
	$(CC) $(CFLAGS) -o $@ $(MAIN) $(SRC)

test: build/$(TEST)
	./build/$(TEST)

build/$(TEST): tests/$(TEST).c $(SRC) dweight.h $(UNITY)/unity.c
	mkdir -p build
	$(CC) $(CFLAGS) -o $@ tests/$(TEST).c $(SRC) $(UNITY)/unity.c

clean:
	rm -rf build $(PROG)

.PHONY: all test clean
