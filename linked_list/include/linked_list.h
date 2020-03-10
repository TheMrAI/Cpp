#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include <memory>

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
    return last_->data;
  }

  [[nodiscard]] auto back() const -> const T&
  {
    return last_->data;
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

private:
  struct list_node
  {
    T data;
    std::unique_ptr<list_node> next;
    list_node* previous;

    explicit list_node(const T& value)
        : data{ value }, next{ nullptr }, previous{ nullptr }
    {
    }
  };

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
  auto next_node = std::make_unique<list_node>(std::move(value));
  if (empty())
  {
    head_ = std::move(next_node);
    last_ = head_.get();
  }
  else
  {
    next_node->previous = last_;
    last_->next = std::move(next_node);
    last_ = last_->next.get();
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
  auto previous_node = std::make_unique<list_node>(std::move(value));
  if (empty())
  {
    head_ = std::move(previous_node);
    last_ = head_.get();
  }
  else
  {
    head_->previous = previous_node.get();
    previous_node->next = std::move(head_);
    head_ = std::move(previous_node);
  }

  ++size_;
}

}  // namespace mrai
#endif  // LINKED_LIST