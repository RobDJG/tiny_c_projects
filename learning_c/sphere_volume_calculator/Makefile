CC      = gcc
UNITY   = ../../vendor/unity
CFLAGS  = -Wall -Wextra -std=gnu11 -I. -I$(UNITY)
LDLIBS  = -lm

PROG    = main
MAIN    = main.c
SRC     = sphere_volume.c
TEST    = test_sphere_volume

all: $(PROG)

$(PROG): $(MAIN) $(SRC) volume_calculator.h
	$(CC) $(CFLAGS) -o $@ $(MAIN) $(SRC) $(LDLIBS)

test: build/$(TEST)
	./build/$(TEST)

build/$(TEST): tests/$(TEST).c $(SRC) volume_calculator.h $(UNITY)/unity.c
	mkdir -p build
	$(CC) $(CFLAGS) -o $@ tests/$(TEST).c $(SRC) $(UNITY)/unity.c $(LDLIBS)

clean:
	rm -rf build $(PROG)

.PHONY: all test clean
