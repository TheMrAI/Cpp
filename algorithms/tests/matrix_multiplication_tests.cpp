#include <gtest/gtest.h>

#include "matrix_multiplication.h"

using namespace mrai;

class matrix_test: public ::testing::Test
{
protected:
  Matrix<int> matrix_data{ 10, 5 };
};

TEST_F(matrix_test, width_is_10)
{
  ASSERT_EQ(matrix_data.width(), 10);
}

TEST_F(matrix_test, height_is_5)
{
  ASSERT_EQ(matrix_data.height(), 5);
}

TEST_F(matrix_test, zeroed_matrix_memory_display_zero_for_all_elements)
{
  memset(matrix_data.matrix_memory().get(), 0,
         matrix_data.width() * matrix_data.height());

  auto& matrix = matrix_data.matrix();
  for (size_t i = 0; i < matrix_data.height(); ++i)
  {
    for (size_t j = 0; j < matrix_data.width(); ++j)
    {
      EXPECT_EQ(matrix[i][j], 0);
    }
  }
}