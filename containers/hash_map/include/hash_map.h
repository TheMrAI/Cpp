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
  using element_type = std::pair<const Key, Value>;
  static constexpr size_t default_bucket_count{ 20 };
  static constexpr float default_maximum_load_factor{ 3.0F };

private:
  using bucket_type = std::list<element_type>;

public:
  class iterator
  {
  public:
    using iterator_category = std::forward_iterator_tag;
    using reference = element_type&;
    using pointer = element_type*;
    using value_type = element_type;
    using difference_type = void;

    iterator( const iterator& rhs );
    iterator( iterator&& rhs ) noexcept;
    ~iterator() = default;
    auto operator=( const iterator& rhs ) -> iterator&;
    auto operator=( iterator&& rhs ) noexcept -> iterator&;
    auto operator==( const iterator& rhs ) const -> bool;
    auto operator!=( const iterator& rhs ) const -> bool;

    auto operator*() -> reference;
    auto operator->() -> pointer;

    auto operator++() -> iterator;
    auto operator++( int ) -> iterator;

  private:
    iterator( hash_map& data_source, std::size_t bucket, typename bucket_type::iterator element );

    hash_map* data_source_{ nullptr };
    std::size_t bucket_{ 0 };
    typename bucket_type::iterator element_;

    friend hash_map;
  };
  friend iterator;

  explicit hash_map( size_t bucket_count = default_bucket_count, const HashFunction& hash = HashFunction(),
                     const KeyEquality& key_equality = KeyEquality() );
  // hash_map(const hash_map& rhs);
  // hash_map(hash_map&& rhs);
  // hash_map& operator=(const hash_map& rhs);
  // hash_map& operator=(hash_map&& rhs);
  //~hash_map();

  auto begin() -> iterator;
  auto end() -> iterator;

  [[nodiscard]] auto empty() const -> bool;
  [[nodiscard]] auto size() const -> size_t;
  auto insert( const element_type& value ) -> std::pair<iterator, bool>;
  // auto insert(element_type&& value) -> std::pair<iterator, bool>;
  // emplace
  auto erase( const Key& key ) -> size_t;
  [[nodiscard]] auto at( const Key& key ) -> Value&;
  [[nodiscard]] auto at( const Key& key ) const -> const Value&;
  [[nodiscard]] auto contains( const Key& key ) -> bool;
  [[nodiscard]] auto find( const Key& key ) -> iterator;

  [[nodiscard]] auto bucket_count() const -> size_t;
  [[nodiscard]] auto max_bucket_count() const -> size_t;
  [[nodiscard]] auto bucket_size( size_t bucket_index ) const -> size_t;
  [[nodiscard]] auto bucket( const Key& key ) const -> size_t;

  [[nodiscard]] auto load_factor() const -> float;
  [[nodiscard]] auto max_load_factor() const -> float;
  auto max_load_factor( float max_load_factor ) -> void;
  auto rehash( size_t bucket_count ) -> void;
  // auto reserve(size_t element_count) -> void;
private:
  auto generate_bucket_index( const Key& key, std::size_t bucket_cout ) const -> std::size_t;

  std::vector<bucket_type> data_;
  std::size_t element_count_{ 0 };
  float maximum_load_factor_{ default_maximum_load_factor };
  const HashFunction hash_{ HashFunction{} };
  const KeyEquality key_equality_{ KeyEquality{} };
};

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
hash_map<Key, Value, HashFunction, KeyEquality>::hash_map( size_t bucket_count, const HashFunction& hash,
                                                           const KeyEquality& key_equality )
    : data_( bucket_count ), hash_{ hash }, key_equality_{ key_equality }
{}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
hash_map<Key, Value, HashFunction, KeyEquality>::iterator::iterator(
    hash_map<Key, Value, HashFunction, KeyEquality>& data_source, std::size_t bucket,
    typename bucket_type::iterator element )
    : data_source_{ &data_source }, bucket_{ bucket }, element_{ element }
{}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
hash_map<Key, Value, HashFunction, KeyEquality>::iterator::iterator( const iterator& rhs )
{
  data_source_ = rhs.data_source_;
  bucket_ = rhs.bucket_;
  element_ = rhs.element_;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
hash_map<Key, Value, HashFunction, KeyEquality>::iterator::iterator( iterator&& rhs ) noexcept
{
  std::swap( data_source_, rhs.data_source_ );
  std::swap( bucket_, rhs.bucket_ );
  std::swap( element_, rhs.element_ );
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::iterator::operator=( const iterator& rhs )
    -> hash_map<Key, Value, HashFunction, KeyEquality>::iterator&
{
  if ( this == &rhs )
  {
    return *this;
  }
  data_source_ = rhs.data_source_;
  bucket_ = rhs.bucket_;
  element_ = rhs.element_;
  return *this;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::iterator::operator=( iterator&& rhs ) noexcept
    -> hash_map<Key, Value, HashFunction, KeyEquality>::iterator&
{
  std::swap( data_source_, rhs.data_source_ );
  std::swap( bucket_, rhs.bucket_ );
  std::swap( element_, rhs.element_ );
  return *this;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::iterator::operator==( const iterator& rhs ) const -> bool
{
  return bucket_ == rhs.bucket_ && element_ == rhs.element_;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::iterator::operator!=( const iterator& rhs ) const -> bool
{
  return !( *this == rhs );
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::iterator::operator*() -> reference
{
  return *element_;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::iterator::operator->() -> pointer
{
  return &( *element_ );
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::iterator::operator++() -> iterator
{
  auto next = element_;
  ++next;
  if ( next != data_source_->data_[bucket_].end() )
  {
    element_ = next;
    return *this;
  }

  for ( std::size_t next_bucket = bucket_ + 1; next_bucket < data_source_->data_.capacity(); ++next_bucket )
  {
    if ( data_source_->data_[next_bucket].begin() != data_source_->data_[next_bucket].end() )
    {
      bucket_ = next_bucket;
      element_ = data_source_->data_[next_bucket].begin();
      return *this;
    }
  }
  *this = data_source_->end();
  return *this;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::iterator::operator++( int ) -> iterator
{
  iterator current = *this;
  ++( *this );
  return current;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::begin()
    -> hash_map<Key, Value, HashFunction, KeyEquality>::iterator
{
  for ( std::size_t i = 0; i < bucket_count(); ++i )
  {
    if ( !data_[i].empty() )
    {
      return hash_map<Key, Value, HashFunction, KeyEquality>::iterator( *this, i, data_[i].begin() );
    }
  }
  return end();
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::end() -> hash_map<Key, Value, HashFunction, KeyEquality>::iterator
{
  std::size_t index = data_.capacity() - 1;
  return hash_map<Key, Value, HashFunction, KeyEquality>::iterator( *this, index, data_[index].end() );
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::empty() const -> bool
{
  return element_count_ == 0;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::size() const -> size_t
{
  return element_count_;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::insert(
    const typename hash_map<Key, Value, HashFunction, KeyEquality>::element_type& value )
    -> std::pair<typename hash_map<Key, Value, HashFunction, KeyEquality>::iterator, bool>
{
  auto key = value.first;
  auto bucket_index = generate_bucket_index( key, data_.capacity() );
  auto possible_location = std::find_if( data_[bucket_index].begin(), data_[bucket_index].end(),
                                         [&key, this]( const element_type& element ) {
                                           return key_equality_( key, element.first );
                                         } );
  if ( possible_location != data_[bucket_index].end() )
  {
    return std::make_pair(
        hash_map<Key, Value, HashFunction, KeyEquality>::iterator( *this, bucket_index, possible_location ), false );
  }
  auto actual_location = data_[bucket_index].insert( possible_location, value );
  ++element_count_;
  /*
  if(max_load_factor() * data_.capacity() < element_count)
  {
    rehash();
  }*/
  return std::make_pair(
      hash_map<Key, Value, HashFunction, KeyEquality>::iterator( *this, bucket_index, actual_location ), true );
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::erase( const Key& key ) -> size_t
{
  std::size_t removed_count = 0;
  auto element_to_remove = find( key );
  if ( element_to_remove != end() )
  {
    data_[element_to_remove.bucket_].erase( element_to_remove.element_ );
    removed_count = 1;
    element_count_ -= 1;
  }
  return removed_count;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::at( const Key& key ) -> Value&
{
  auto element = find( key );
  if ( element == end() )
  {
    throw std::out_of_range( "Invalid key!" );
  }
  return element->second;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::at( const Key& key ) const -> const Value&
{
  return at( key );
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::contains( const Key& key ) -> bool
{
  auto target = find( key );
  return target != end();
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::find( const Key& key ) -> iterator
{
  auto bucket_index = generate_bucket_index( key, data_.capacity() );
  auto searched_element =
      std::find_if( data_[bucket_index].begin(), data_[bucket_index].end(), [&key]( const element_type& element ) {
        return key == element.first;
      } );
  if ( searched_element == data_[bucket_index].end() )
  {
    return end();
  }
  return iterator{ *this, bucket_index, searched_element };
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::bucket_count() const -> size_t
{
  return data_.capacity();
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::max_bucket_count() const -> size_t
{
  return std::numeric_limits<std::size_t>::max();
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::bucket_size( size_t bucket_index ) const -> size_t
{
  return data_[bucket_index].size();
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::bucket( const Key& key ) const -> size_t
{
  return generate_bucket_index( key, data_.capacity() );
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::load_factor() const -> float
{
  return element_count_ / bucket_count();
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::max_load_factor() const -> float
{
  return maximum_load_factor_;
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::max_load_factor( float max_load_factor ) -> void
{
  maximum_load_factor_ = max_load_factor;
  /*if(load_factor() > max_load_factor)
  {
    rehash();
  }*/
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::rehash( size_t bucket_count ) -> void
{
  auto minimum_bucket_count = static_cast<std::size_t>( size() / max_load_factor() );
  auto new_bucket_count = std::max( minimum_bucket_count, bucket_count );

  auto new_data = std::vector<bucket_type>{ new_bucket_count };

  for ( auto element : *this )
  {
    auto key = element.first;
    auto bucket_index = generate_bucket_index( key, new_bucket_count );
    new_data[bucket_index].push_back( std::move( element ) );
  }
  std::swap( data_, new_data );
}

template <typename Key, typename Value, typename HashFunction, typename KeyEquality>
auto hash_map<Key, Value, HashFunction, KeyEquality>::generate_bucket_index( const Key& key,
                                                                             std::size_t bucket_cout ) const
    -> std::size_t
{
  auto hash_code = hash_( key );
  return hash_code % bucket_cout;
}

}  // namespace mrai
#endif  // HASH_MAP