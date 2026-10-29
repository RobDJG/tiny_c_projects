# Unit testing with Unity

This repo uses [Unity](https://github.com/ThrowTheSwitch/Unity), a small unit-test framework for C written in plain C.
It is **vendored**: the three files it needs live in [`vendor/unity/`](vendor/unity/) (version **v2.7.0**, MIT license).
You don't need to install anything except `gcc` and `make`.

```
tiny_c_projects/
├── vendor/unity/          unity.c, unity.h, unity_internals.h
└── 01_daily_greetings/
    ├── greeting.h / .c    the logic (what we test)
    ├── hello.c            main() only
    ├── Makefile
    └── tests/test_greeting.c
```

## Quick start

```bash
cd 01_daily_greetings
make          # build the program  -> ./hello
make test     # build and run the tests
make clean    # delete build output
```

## The one rule: keep logic out of `main()`

A test file has its own `main()` (the test runner), and a C program can only have one `main`.
So the code you want to test **can't live in the same file as your program's `main()`**.

Split each project like this:

| File | Contains |
|------|----------|
| `thing.h` | function declarations |
| `thing.c` | function definitions, **no `main`** |
| `app.c` | `int main(void)` that calls the functions |
| `tests/test_thing.c` | tests plus the runner `main` |

The program is built from `app.c` + `thing.c`. The tests are built from `tests/test_thing.c` + `thing.c` + `unity.c`.

Tip: functions that **return** a value or **write into a buffer** are easy to test. Functions that only `printf` are not, so have them build the string and let `main` print it (that's what `build_greeting` does).

## Anatomy of a test file

```c
#include "unity.h"
#include "greeting.h"          /* the code under test */

void setUp(void) {}            /* runs before EVERY test (required, may be empty) */
void tearDown(void) {}         /* runs after EVERY test  (required, may be empty) */

void test_greets_by_name(void) /* tests: void, no args, name starts with test_ */
{
    char out[32];                                  /* Arrange */
    build_greeting("Ada", out, sizeof out);        /* Act     */
    TEST_ASSERT_EQUAL_STRING("Hello, Ada!", out);  /* Assert  */
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_greets_by_name);   /* every test must be listed here */
    return UNITY_END();              /* returns number of failures -> exit code */
}
```

When an assertion fails, that test stops right away and Unity moves on to the next one.
**Forgetting the `RUN_TEST` line is the most common mistake**: the test compiles but never runs.

## Common assertions

Convention: **expected first, actual second**.

| Assertion | Checks |
|-----------|--------|
| `TEST_ASSERT_TRUE(cond)` / `TEST_ASSERT_FALSE(cond)` | a condition |
| `TEST_ASSERT_EQUAL_INT(expected, actual)` | ints (also `_UINT`, `_CHAR`, `_HEX8`, …) |
| `TEST_ASSERT_EQUAL_STRING(expected, actual)` | C strings (`strcmp`-style) |
| `TEST_ASSERT_EQUAL_STRING_LEN(exp, act, n)` | first `n` chars |
| `TEST_ASSERT_FLOAT_WITHIN(delta, expected, actual)` | floats, since exact `==` is unreliable |
| `TEST_ASSERT_EQUAL_DOUBLE(expected, actual)` | doubles |
| `TEST_ASSERT_NULL(ptr)` / `TEST_ASSERT_NOT_NULL(ptr)` | pointers |
| `TEST_ASSERT_EQUAL_INT_ARRAY(exp, act, count)` | whole arrays |
| `TEST_ASSERT_EQUAL_MEMORY(exp, act, bytes)` | raw memory / structs |
| `TEST_ASSERT_GREATER_THAN(threshold, actual)` | also `_LESS_THAN`, `_INT_WITHIN` |
| `TEST_FAIL_MESSAGE("why")` | fail on purpose |
| `TEST_IGNORE_MESSAGE("todo")` | skip a test for now |

Most assertions have a `_MESSAGE` version that adds context to the failure,
e.g. `TEST_ASSERT_EQUAL_INT_MESSAGE(3, n, "wrong word count")`.
The full list is in [`vendor/unity/unity.h`](vendor/unity/unity.h).

## Running tests

With make:

```bash
make test
```

Without make (this is all the Makefile does):

```bash
gcc -Wall -Wextra -std=c11 -I. -I../vendor/unity \
    -o build/test_greeting tests/test_greeting.c greeting.c ../vendor/unity/unity.c
./build/test_greeting
```

### Reading the output

```
tests/test_greeting.c:38:test_greets_by_name:PASS
tests/test_greeting.c:19:test_empty_name_gives_plain_hello:FAIL: Expected 'Hello!' Was 'Hello, !'
...
-----------------------
4 Tests 1 Failures 0 Ignored
FAIL
```

Each line shows `file:line:test_name:RESULT`. For a failure, the line number points at the assertion that failed and the message tells you expected vs. actual.
The program exits with the number of failures, so `make` stops with `Error 1` when anything fails, and `&&` chains won't continue.

## Adding tests to a new project

1. Put the logic in `thing.c` / `thing.h` and keep `main()` in its own file.
2. `mkdir tests` and create `tests/test_thing.c` (copy the skeleton above).
3. Copy `01_daily_greetings/Makefile` and change:
   - `SRC = thing.c` (list every `.c` file except the one with your `main`)
   - `hello` → your program name, `hello.c` → your main file
   - `test_greeting` → `test_thing`
4. Add your program's binary to `.gitignore`.
5. `make test`

Workflow tip: write a failing test first, run `make test` and see it go red, then write the code until it turns green.
