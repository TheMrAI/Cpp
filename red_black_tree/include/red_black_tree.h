#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include <functional>
#include <memory>

namespace mrai
{
// Red-black tree properties
// 1. A node is either red or black.
// 2. The root and leaves (NIL) are black.
// 3. If a node is red, then its children are black.
// 4. All paths from a node to is NIL descendants contain the same
//    number of black nodes.
template <typename Key, typename Compare = std::less<Key>>
class rb_tree
{
private:
  enum class Color
  {
    RED,
    BLACK
  };

  struct red_black_node
  {
    red_black_node* parrent;
    std::unique_ptr<red_black_node> left;
    std::unique_ptr<red_black_node> right;
    Color color;
  };

public:
  explicit rb_tree(const Compare& comparator = Compare());

  class iterator
  {
  };

  /*
  auto begin() -> iterator;
  auto end() -> iterator;
  */
  auto empty() const noexcept -> bool;
  auto size() const noexcept -> size_t;

  /*
  auto clear() -> void;
  auto contains() -> bool;

  auto find() -> iterator;
  auto insert() -> std::pair<iterator, bool>;
  auto erase() -> void;*/
private:
  Compare comparator_;
  std::size_t size_;
};

template <typename Key, typename Compare>
rb_tree<Key, Compare>::rb_tree(const Compare& comparator)
    : comparator_{ comparator }, size_{ 0 }
{
}

template <typename Key, typename Compare>
auto rb_tree<Key, Compare>::empty() const noexcept -> bool
{
  return size_ == 0;
}

template <typename Key, typename Compare>
auto rb_tree<Key, Compare>::size() const noexcept -> size_t
{
  return size_;
}

}  // namespace mrai
#endif  // RED_BLACK_TREE