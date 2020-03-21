#ifndef LINKED_LIST
#define LINKED_LIST

#include <iterator>
#include <memory>
#include <utility>

namespace mrai
{
template <typename T>
class linked_list
{
public:
  linked_list();
  /*
  linked_list(const linked_list& rhs);
  linked_list(linked_list&& rhs);
  linked_list& operator=(const linked_list& rhs);
  linked_list& operator=(linked_list&& rhs);
  ~linked_list();
  */

  [[nodiscard]] auto front() -> T&
  {
    return head_->data;
  }

  [[nodiscard]] auto front() const -> const T&
  {
    return head_->data;
  }

  [[nodiscard]] auto back() -> T&
  {
    return last_->previous->data;
  }

  [[nodiscard]] auto back() const -> const T&
  {
    return last_->previous->data;
  }

  [[nodiscard]] auto size() const noexcept -> size_t
  {
    return size_;
  }

  [[nodiscard]] auto empty() const noexcept -> bool
  {
    return size_ == 0;
  }

  auto push_back(const T& value) -> void;
  auto push_back(T&& value) -> void;
  auto push_front(const T& value) -> void;
  auto push_front(T&& value) -> void;

  struct list_node
  {
    T data;
    std::unique_ptr<list_node> next;
    list_node* previous;

    explicit list_node(const T& value)
        : data{ value }, next{ nullptr }, previous{ nullptr }
    {
    }
    ~list_node() = default;
    list_node(list_node const& rhs) = delete;
    list_node(list_node&& rhs)
    {
      *this = rhs;
    }
    list_node& operator=(list_node const&) = delete;
    list_node& operator=(list_node&& rhs)
    {
      std::swap(this->data, rhs.data);
      std::swap(this->next, rhs.next);
      std::swap(this->previous, rhs.previous);
      return *this;
    }
  };

  class iterator
  {
  public:
    using iterator_category = std::bidirectional_iterator_tag;
    using reference = T&;
    using pointer = T*;
    using value_type = T;
    using difference_type = void;

    iterator(list_node* element);
    /*iterator(iterator const & rhs);
    iterator(iterator&& rhs);
    iterator& operator++(); // pre increment
    iterator& operator++(int); // post increment
    iterator& operator--();
    iterator& operator--(int);
    iterator& operator=(iterator const & rhs);
    iterator& operator=(iterator && rhs);
    auto operator==(iterator const & rhs) -> bool;
    auto operator!=(iterator const & rhs) -> bool;
    auto operator*() -> reference;
    auto operator->() -> reference;*/
  private:
    list_node* element_;
  };

  auto begin() -> iterator;
  auto end() -> iterator;
  /*auto cbegin() -> const_iterator;
  auto cend() -> const_iterator;*/

private:
  std::unique_ptr<list_node> head_;
  list_node* last_;
  size_t size_;
};

template <typename T>
linked_list<T>::linked_list(): head_{ nullptr }, last_{ nullptr }, size_{ 0 }
{
}

template <typename T>
auto linked_list<T>::push_back(const T& value) -> void
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
    head_ = std::move(next_node);
    head_->next = std::make_unique<list_node>(T());
    last_ = head_->next.get();
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
auto linked_list<T>::push_front(const T& value) -> void
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
    head_ = std::move(previous_node);
    head_->next = std::make_unique<list_node>(T());
    last_ = head_->next.get();
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
linked_list<T>::iterator::iterator(linked_list<T>::list_node* element)
    : element_{ element }
{
}

template <typename T>
auto linked_list<T>::begin() -> linked_list<T>::iterator
{
  return linked_list<T>::iterator(*head_);
}

template <typename T>
auto linked_list<T>::end() -> linked_list<T>::iterator
{
  return linked_list<T>::iterator(last_);
}

}  // namespace mrai
#endif  // LINKED_LIST