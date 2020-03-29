#ifndef HASH_MAP
#define HASH_MAP

#include <functional>
#include <list>
#include <vector>

namespace mrai
{
template <typename Key, typename Value, typename HashFunction = std::hash<Key>,
          typename KeyEquality = std::equal_to<Key>>
class hash_map
{
public:
  explicit hash_map(size_t bucket_count = 20,
                    const HashFunction& hash = HashFunction(),
                    const KeyEquality& key_equality = KeyEquality());
  // hash_map(const hash_map& rhs);
  // hash_map(hash_map&& rhs);
  // hash_map& operator=(const hash_map& rhs);
  // hash_map& operator=(hash_map&& rhs);
  //~hash_map();

  // auto empty() -> bool;
  // auto size() -> size_t;
  // auto insert() -> std::pair<iterator, bool>;
  // emplace
  // auto erase() ->  size_t;
  // auto at(const Key& key) -> Value&l
  // auto contains(const Key& key) -> bool;
  // auto find(const Key& key) -> iterator;

  // auto bucket_count() const -> size_t;
  // auto max_bucket_count() constexpr -> size_t;
  // auto bucket_size(size_t bucket_index) const -> size_t;
  // auto bucket(const Key& key) const -> size_t;

  // auto load_factor() const -> float;
  // auto max_load_factor() const -> float;
  // auot max_load_factor(float max_load_factor) -> void;
  // auto rehash(size_t bucket_count) -> void;
  // auto reserve(size_t element_count) -> void;
private:
  using value_type = std::pair<Key, Value>;
  using bucket = std::list<value_type>;

  std::vector<bucket> data_;
  const HashFunction hash_;
  const KeyEquality key_equality_;
};

template <typename Key, typename Value, typename HashFunction,
          typename KeyEquality>
hash_map<Key, Value, HashFunction, KeyEquality>::hash_map(
    size_t bucket_count, const HashFunction& hash,
    const KeyEquality& key_equality)
    : data_(bucket_count), hash_{ hash }, key_equality_{ key_equality }
{
}

}  // namespace mrai
#endif  // HASH_MAP