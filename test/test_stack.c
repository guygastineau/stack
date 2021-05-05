#include "vendor/unity.h"
#include "../src/stack.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_mkStack(void)
{
  Stack st = mkStack();
  TEST_ASSERT_NULL_MESSAGE(st, "Failed to return NULL from mkStack");
}

static void test_push_one(void)
{
  Stack st = mkStack();
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 1),
                                "Failed to push to stack");
  TEST_ASSERT_EQUAL_size_t_MESSAGE(1, stLength(&st),
                                   "Stack is incorrect length after pushing");
  stDestroy(&st, NULL);

  TEST_ASSERT_NULL_MESSAGE(st, "st wasn't NULL after Stack deallocation");
}

static void test_push_several(void)
{
  Stack st = mkStack();
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 1),
                                "Failed to push to stack");
  TEST_ASSERT_EQUAL_size_t_MESSAGE(1, stLength(&st),
                                   "Stack is incorrect length after pushing");

  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 2),
                                "Failed to push to stack");
  TEST_ASSERT_EQUAL_size_t_MESSAGE(2, stLength(&st),
                                   "Stack is incorrect length after pushing");

  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 3),
                                "Failed to push to stack");
  TEST_ASSERT_EQUAL_size_t_MESSAGE(3, stLength(&st),
                                   "Stack is incorrect length after pushing");

  stDestroy(&st, NULL);

  TEST_ASSERT_NULL_MESSAGE(st, "st wasn't NULL after Stack deallocation");

}

static void test_pop_one(void)
{
  Stack st = mkStack();
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 1),
                                "Failed to push to stack");
  SData data;
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPop(&st, &data),
                                "Failed to pop singleton from stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, data, "Got wrong data from popping");

  TEST_ASSERT_EQUAL_size_t_MESSAGE(0, stLength(&st),
                                   "stPop didn't change the length");

  stDestroy(&st, NULL);

  TEST_ASSERT_NULL_MESSAGE(st, "st wasn't NULL after Stack deallocation");
}

static void test_pop_several(void)
{
  Stack st = mkStack();
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 1),
                                "Failed to push to stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 2),
                                "Failed to push to stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 3),
                                "Failed to push to stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 4),
                                "Failed to push to stack");
  SData data;

  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPop(&st, &data),
                                "Failed to pop singleton from stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(4, data, "Got wrong data from popping");

  TEST_ASSERT_EQUAL_size_t_MESSAGE(3, stLength(&st),
                                   "stPop didn't change the length");

  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPop(&st, &data),
                                "Failed to pop singleton from stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(3, data, "Got wrong data from popping");

  TEST_ASSERT_EQUAL_size_t_MESSAGE(2, stLength(&st),
                                   "stPop didn't change the length");

  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPop(&st, &data),
                                "Failed to pop singleton from stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(2, data, "Got wrong data from popping");

  TEST_ASSERT_EQUAL_size_t_MESSAGE(1, stLength(&st),
                                   "stPop didn't change the length");

  // Left one, so we need to destroy it.

  stDestroy(&st, NULL);

  TEST_ASSERT_NULL_MESSAGE(st, "st wasn't NULL after Stack deallocation");
}

static void test_peek_one(void)
{
  Stack st = mkStack();
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 1),
                                "Failed to push to stack");
  SData data;
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPeek(&st, &data),
                                "Failed to peek singleton from stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, data, "Got wrong data from peeking");

  TEST_ASSERT_EQUAL_size_t_MESSAGE(1, stLength(&st),
                                   "stPeek changed the length unexpectedly");

  stDestroy(&st, NULL);

  TEST_ASSERT_NULL_MESSAGE(st, "st wasn't NULL after Stack deallocation");
}

static void test_peek_several(void)
{
  Stack st = mkStack();
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 1),
                                "Failed to push to stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 2),
                                "Failed to push to stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 3),
                                "Failed to push to stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPush(&st, 4),
                                "Failed to push to stack");
  SData data;

  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPeek(&st, &data),
                                "Failed to peek singleton from stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(4, data, "Got wrong data from peeking");

  TEST_ASSERT_EQUAL_size_t_MESSAGE(4, stLength(&st),
                                   "stPeek changed the length unexpectedly");

  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPop(&st, &data),
                                "Failed to pop singleton from stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(3, data, "Got wrong data from popping");

  TEST_ASSERT_EQUAL_size_t_MESSAGE(3, stLength(&st),
                                   "stPop didn't change the length");

  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPeek(&st, &data),
                                "Failed to peek singleton from stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(3, data, "Got wrong data from peeking");

  TEST_ASSERT_EQUAL_size_t_MESSAGE(3, stLength(&st),
                                   "stPeek changed the length unexpectedly");

  // Chewck and make sure peek returns the same data back to back.
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, stPeek(&st, &data),
                                "Failed to peek singleton from stack");
  TEST_ASSERT_EQUAL_INT_MESSAGE(3, data, "Got wrong data from peeking");

  TEST_ASSERT_EQUAL_size_t_MESSAGE(3, stLength(&st),
                                   "stPeek changed the length unexpectedly");

  // Left one, so we need to destroy it.

  stDestroy(&st, NULL);

  TEST_ASSERT_NULL_MESSAGE(st, "st wasn't NULL after Stack deallocation");
}

int main(void)
{
   UnityBegin("test/test_stack.c");

   RUN_TEST(test_mkStack);
   RUN_TEST(test_push_one);
   RUN_TEST(test_push_several);
   RUN_TEST(test_pop_one);
   RUN_TEST(test_pop_several);
   RUN_TEST(test_peek_one);
   RUN_TEST(test_peek_several);

   return UnityEnd();
}
