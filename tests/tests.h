#ifndef TESTS_THREADS_TESTS_H
#define TESTS_THREADS_TESTS_H

void run_test (const char *);

typedef void test_func (void);

struct test 
  {
    const char *name;
    test_func *function;
  };




extern test_func test_hello_world;
extern test_func test_fifo_simple;
extern test_func test_round_robin_simple;
extern test_func test_round_robin_1tick;
extern test_func test_fifo_random_duration;
extern test_func test_round_robin_random_duration;
extern test_func test_fifo_delayed_create;
extern test_func test_round_robin_delayed_create;
extern test_func test_sleep_single;
extern test_func test_sleep_multiple_fifo;
extern test_func test_sleep_multiple_rr;
extern test_func test_sleep_negative;
extern test_func test_temp_test;

int getNumberOfTests(void);
char* getTestName(int testN);
void print_test_names(void);
void msg (const char *, ...);
void fail (const char *, ...);
void pass (void);

#endif /* tests/threads/tests.h */

