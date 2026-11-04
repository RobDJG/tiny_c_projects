CC      = gcc
UNITY   = ../../vendor/unity
CFLAGS  = -Wall -Wextra -std=c11 -I. -I$(UNITY)

PROG    = celsius
MAIN    = celsius.c
SRC     = temperature_conversion.c
TEST    = test_celsius

all: $(PROG)

$(PROG): $(MAIN) $(SRC) celsius.h
	$(CC) $(CFLAGS) -o $@ $(MAIN) $(SRC)

test: build/$(TEST)
	./build/$(TEST)

build/$(TEST): tests/$(TEST).c $(SRC) celsius.h $(UNITY)/unity.c
	mkdir -p build
	$(CC) $(CFLAGS) -o $@ tests/$(TEST).c $(SRC) $(UNITY)/unity.c

clean:
	rm -rf build $(PROG)

.PHONY: all test clean
