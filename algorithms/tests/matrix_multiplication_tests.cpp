#include <gtest/gtest.h>

#include "matrix_multiplication.h"

using namespace mrai;

TEST(nyo, nya)
{
  auto matrix_memory = allocate_matrix<int>(10, 10);
  auto something = setup_matrix_pointers(matrix_memory, 10, 10);
  ASSERT_TRUE(false);
}