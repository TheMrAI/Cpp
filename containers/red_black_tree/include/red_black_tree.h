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
    Key key;
  };

public:
  explicit rb_tree(const Compare& comparator = Compare());

  class const_iterator
  {
  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using reference = const Key&;
    using pointer = const Key*;
    using value_type = Key;
    using difference_type = void;

    const_iterator(const const_iterator& rhs);
    const_iterator(const_iterator&& rhs);
    /*auto operator=(const const_iterator& rhs) -> const_iterator&;
    auto operator=(const_iterator&& rhs) -> const_iterator&;
    */
    auto operator==(const const_iterator& rhs) const -> bool;
    /*auto operator++() -> const_iterator&;
    auto operator++(int) -> const_iterator&;
    auto operator--() -> const_iterator&;
    auto operator--(int) -> const_iterator&;
    */
    auto operator*() -> reference;
    auto operator-> () -> pointer;

  private:
    explicit const_iterator(red_black_node* element);

    const red_black_node* element_;

    friend rb_tree;
  };

  auto cbegin() -> const_iterator;
  auto cend() -> const_iterator;

  auto empty() const noexcept -> bool;
  auto size() const noexcept -> size_t;

  /*
  auto clear() -> void;
  auto contains() -> bool;

  auto find() -> const_iterator;
  auto insert() -> std::pair<const_iterator, bool>;
  auto erase() -> void;*/
private:
  Compare comparator_;
  std::size_t size_;
  std::unique_ptr<red_black_node> root_;
};

template <typename Key, typename Compare>
rb_tree<Key, Compare>::const_iterator::const_iterator(red_black_node* element)
    : element_{ element }
{
}

template <typename Key, typename Compare>
rb_tree<Key, Compare>::const_iterator::const_iterator(const const_iterator& rhs)
{
  element_ = rhs.element;
}

template <typename Key, typename Compare>
rb_tree<Key, Compare>::const_iterator::const_iterator(const_iterator&& rhs)
{
  std::swap(element_, rhs.element_);
}

template <typename Key, typename Compare>
auto rb_tree<Key, Compare>::const_iterator::operator==(
    const const_iterator& rhs) const -> bool
{
  // comparing only the pointers, if they both null it's okay
  // if they point to the exact same object it is okay as well
  return element_ == rhs.element_;
}

template <typename Key, typename Compare>
auto rb_tree<Key, Compare>::const_iterator::operator*() -> reference
{
  return element_->key;
}

template <typename Key, typename Compare>
auto rb_tree<Key, Compare>::const_iterator::operator-> () -> pointer
{
  return *(element_->key);
}

template <typename Key, typename Compare>
rb_tree<Key, Compare>::rb_tree(const Compare& comparator)
    : comparator_{ comparator }, size_{ 0 }
{
}

template <typename Key, typename Compare>
auto rb_tree<Key, Compare>::cbegin() -> const_iterator
{
  return const_iterator{ root_.get() };
}

template <typename Key, typename Compare>
auto rb_tree<Key, Compare>::cend() -> const_iterator
{
  return const_iterator{ nullptr };
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