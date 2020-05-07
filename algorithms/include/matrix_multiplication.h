#ifndef ALGORITHMS_MATRIX_MULTIPLICATION
#define ALGORITHMS_MATRIX_MULTIPLICATION

#include <memory>
#include <utility>

namespace mrai
{
template <typename T>
using matrix_data = std::pair<std::unique_ptr<T*[]>, std::unique_ptr<T[]>>;

template <typename T>
auto allocate_matrix(size_t width, size_t height) -> matrix_data<T>
{
  auto continuous_memory = std::make_unique<T[]>(width * height);
  auto matrix_pointer = std::make_unique<T*[]>(height);

  for (size_t row = 0; row < height; ++row)
  {
    matrix_pointer[row] = &continuous_memory[row * width];
  }
  return std::make_pair(std::move(matrix_pointer),
                        std::move(continuous_memory));
}

template <typename T>
class Matrix
{
public:
  Matrix(size_t width, size_t height);
  ~Matrix() = default;

  Matrix(Matrix& rhs) = delete;
  Matrix(Matrix&& rhs) noexcept = default;
  auto operator=(const Matrix& rhs) -> Matrix& = default;
  auto operator=(Matrix&& rhs) noexcept -> Matrix& = default;

  [[nodiscard]] auto width() const noexcept -> size_t;
  [[nodiscard]] auto height() const noexcept -> size_t;
  [[nodiscard]] auto matrix() -> std::unique_ptr<T*[]>&;
  [[nodiscard]] auto matrix_memory() -> std::unique_ptr<T[]>&;

private:
  size_t width_;
  size_t height_;

  std::unique_ptr<T*[]> matrix_;
  std::unique_ptr<T[]> matrix_memory_;
};

template <typename T>
Matrix<T>::Matrix(size_t width, size_t height)
    : width_{ width }, height_{ height }
{
  std::tie(matrix_, matrix_memory_) = allocate_matrix<T>(width, height);
}

template <typename T>
auto Matrix<T>::width() const noexcept -> size_t
{
  return width_;
}

template <typename T>
auto Matrix<T>::height() const noexcept -> size_t
{
  return height_;
}

template <typename T>
auto Matrix<T>::matrix() -> std::unique_ptr<T* []>& {
  return matrix_;
}

template <typename T>
auto Matrix<T>::matrix_memory() -> std::unique_ptr<T[]>&
{
  return matrix_memory_;
}

}  // namespace mrai
#endif  // ALGORITHMS_MATRIX_MULTIPLICATION