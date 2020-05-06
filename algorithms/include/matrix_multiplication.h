#ifndef ALGORITHMS_MATRIX_MULTIPLICATION
#define ALGORITHMS_MATRIX_MULTIPLICATION

#include <memory>
#include <utility>

namespace mrai
{
template <typename T>
auto allocate_matrix(size_t width, size_t height) -> std::unique_ptr<T[]>
{
  auto continuous_memory = std::make_unique<T[]>(width * height);

  return continuous_memory;
}

template <typename T>
auto setup_matrix_pointers(std::unique_ptr<T[]>& matrix, size_t width,
                           size_t height) -> std::unique_ptr<T* []> {
  auto matrix_pointer = std::make_unique<T*[]>(height);

  for (size_t row = 0; row < height; ++row)
  {
    matrix_pointer[row] = &matrix[row * width];
  }
  return matrix_pointer;
}

}  // namespace mrai
#endif  // ALGORITHMS_MATRIX_MULTIPLICATION