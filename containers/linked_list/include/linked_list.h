#ifndef LINKED_LIST
#define LINKED_LIST

#include <iterator>
#include <memory>
#include <type_traits>
#include <utility>

namespace mrai
{
template <typename T>
class linked_list
{
private:
  struct list_node;  // forward declaration
public:
  class iterator
  {
  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using reference = T&;
    using pointer = T*;
    using value_type = T;
    using difference_type = void;

    explicit iterator(list_node* element = nullptr);
    /*iterator(iterator const & rhs);
    iterator(iterator&& rhs);
    iterator& operator++(); // pre increment
    iterator& operator++(int); // post increment
    iterator& operator--();
    iterator& operator--(int);
    iterator& operator=(iterator const & rhs);
    iterator& operator=(iterator && rhs);*/
    auto operator==(iterator const& rhs) const -> bool;
    auto operator!=(iterator const& rhs) const -> bool;
    auto operator*() -> reference;
    auto operator-> () -> reference;

  private:
    list_node* element_;
  };

  linked_list();
  /*
  linked_list(const linked_list& rhs);
  linked_list(linked_list&& rhs);
  linked_list& operator=(const linked_list& rhs);
  linked_list& operator=(linked_list&& rhs);
  ~linked_list();
  */

  [[nodiscard]] auto front() -> T&;
  [[nodiscard]] auto front() const -> const T&;
  [[nodiscard]] auto back() -> T&;
  [[nodiscard]] auto back() const -> const T&;
  [[nodiscard]] auto size() const noexcept -> size_t;
  [[nodiscard]] auto empty() const noexcept -> bool;

  auto push_back(T const& value) -> void;
  auto push_back(T&& value) -> void;
  auto push_front(T const& value) -> void;
  auto push_front(T&& value) -> void;

  // emplace_back()
  // emplace_front();

  auto pop_back() -> void;
  auto pop_front() -> void;

  // insert()
  // emplace()
  // erase()
  // clear()

  auto begin() -> iterator;
  auto end() -> iterator;
  /*auto cbegin() -> const_iterator;
  auto cend() -> const_iterator;*/

private:
  struct list_node
  {
    T data;
    std::unique_ptr<list_node> next;
    list_node* previous;

    explicit list_node(T const& value);
    ~list_node() = default;
    list_node(list_node const& rhs) = delete;
    list_node(list_node&& rhs) noexcept;
    auto operator=(list_node const&) -> list_node& = delete;
    auto operator=(list_node&& rhs) noexcept -> list_node&;
  };

  std::unique_ptr<list_node> head_;
  list_node* last_;
  size_t size_;
};

template <typename T>
linked_list<T>::linked_list()
    : head_{ std::make_unique<list_node>(T{}) },
      last_{ head_.get() },
      size_{ 0 }
{
}

template <typename T>
[[nodiscard]] auto linked_list<T>::front() -> T&
{
  return head_->data;
}

template <typename T>
[[nodiscard]] auto linked_list<T>::front() const -> const T&
{
  return head_->data;
}

template <typename T>
[[nodiscard]] auto linked_list<T>::back() -> T&
{
  return last_->previous->data;
}

template <typename T>
[[nodiscard]] auto linked_list<T>::back() const -> const T&
{
  return last_->previous->data;
}

template <typename T>
[[nodiscard]] auto linked_list<T>::size() const noexcept -> size_t
{
  return size_;
}

template <typename T>
[[nodiscard]] auto linked_list<T>::empty() const noexcept -> bool
{
  return size_ == 0;
}

template <typename T>
auto linked_list<T>::push_back(T const& value) -> void
{
  T value_copy{ value };
  this->push_back(std::move(value_copy));
}

template <typename T>
auto linked_list<T>::push_back(T&& value) -> void
{
  auto next_node = std::make_unique<list_node>(std::forward<T>(value));
  if (empty())
  {
    next_node->next = std::move(head_);
    head_ = std::move(next_node);
    last_->previous = head_.get();
  }
  else
  {
    next_node->previous = last_->previous;
    last_->previous = next_node.get();
    next_node->next = std::move(next_node->previous->next);
    next_node->previous->next = std::move(next_node);
  }

  ++size_;
}

template <typename T>
auto linked_list<T>::push_front(T const& value) -> void
{
  T value_copy{ value };
  this->push_front(std::move(value_copy));
}

template <typename T>
auto linked_list<T>::push_front(T&& value) -> void
{
  auto previous_node = std::make_unique<list_node>(std::forward<T>(value));
  if (empty())
  {
    previous_node->next = std::move(head_);
    head_ = std::move(previous_node);
    last_->previous = head_.get();
  }
  else
  {
    head_->previous = previous_node.get();
    previous_node->next = std::move(head_);
    head_ = std::move(previous_node);
  }

  ++size_;
}

template <typename T>
auto linked_list<T>::pop_back() -> void
{
  if (this->size() <= 1)
  {
    pop_front();
    return;
  }
  auto* before_last = last_->previous->previous;
  before_last->next = std::move(last_->previous->next);
  last_->previous = before_last;

  --size_;
}

template <typename T>
auto linked_list<T>::pop_front() -> void
{
  if (empty())
  {
    return;
  }

  head_ = std::move(head_->next);
  head_->previous = nullptr;

  --size_;
}

template <typename T>
linked_list<T>::iterator::iterator(linked_list<T>::list_node* element)
    : element_{ element }
{
}

template <typename T>
auto linked_list<T>::begin() -> linked_list<T>::iterator
{
  return linked_list<T>::iterator(head_.get());
}

template <typename T>
auto linked_list<T>::end() -> linked_list<T>::iterator
{
  return linked_list<T>::iterator(last_);
}

template <typename T>
linked_list<T>::list_node::list_node(T const& value)
    : data{ value }, next{ nullptr }, previous{ nullptr }
{
}

template <typename T>
linked_list<T>::list_node::list_node(linked_list<T>::list_node&& rhs) noexcept
{
  *this = std::move(rhs);
}

template <typename T>
auto linked_list<T>::list_node::operator=(list_node&& rhs) noexcept
    -> linked_list<T>::list_node&
{
  std::swap(this->data, rhs.data);
  std::swap(this->next, rhs.next);
  std::swap(this->previous, rhs.previous);
  return *this;
}

template <typename T>
auto linked_list<T>::iterator::operator==(iterator const& rhs) const -> bool
{
  return this->element_ == rhs.element_;
}

template <typename T>
auto linked_list<T>::iterator::operator!=(iterator const& rhs) const -> bool
{
  return !(*this == rhs);
}

template <typename T>
auto linked_list<T>::iterator::operator*() -> reference
{
  if constexpr (std::is_pointer<T>())
  {
    return *(element_->data);
  }
  else
  {
    return element_->data;
  }
}

template <typename T>
auto linked_list<T>::iterator::operator-> () -> reference
{
  return element_->data;
}

}  // namespace mrai
#endif  // LINKED_LIST