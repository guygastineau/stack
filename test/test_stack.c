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

int main(void)
{
   UnityBegin("test/test_stack.c");

   RUN_TEST(test_mkStack);
   RUN_TEST(test_push_one);
   RUN_TEST(test_push_several);

   return UnityEnd();
}
