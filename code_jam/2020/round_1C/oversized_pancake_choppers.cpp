#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

auto can_make_enough_cuts( uint64_t target_size, uint64_t D, std::vector<uint64_t> const& slices ) -> bool
{
  if ( target_size == 0 )
  {
    return false;
  }
  auto slice_count = 0U;
  // checking slices from the back as at this point slices are ordered in non-descending order
  for ( auto slice = slices.crbegin(); slice != slices.crend(); ++slice )
  {
    slice_count += *slice / target_size;
    if ( slice_count >= D )
    {
      return true;
    }
  }
  return false;
}

auto find_maximum_target_slice_size( uint64_t D, std::vector<uint64_t> const& slices ) -> uint64_t
{
  auto low_piece_count = 1U;
  auto high_piece_count = D;

  auto biggest_slice = slices.back();
  while ( low_piece_count < high_piece_count )
  {
    auto middle_piece_count = low_piece_count + ( high_piece_count - low_piece_count ) / 2;
    auto target_size = biggest_slice / middle_piece_count;

    if ( can_make_enough_cuts( target_size, D, slices ) )
    {
      high_piece_count = middle_piece_count;
    }
    else
    {
      low_piece_count = middle_piece_count + 1;
    }
  }

  return biggest_slice / high_piece_count;
}

auto get_reduced_fraction( uint64_t const& nominator, uint64_t const& denominator ) -> std::pair<uint64_t, uint64_t>
{
  // smaller will be the greatest common divisor
  auto smaller = nominator;
  auto larger = denominator;
  if ( smaller > larger )
  {
    std::swap( smaller, larger );
  }

  auto modulus = larger % smaller;
  while ( modulus != 0 )
  {
    larger = smaller;
    smaller = modulus;
    modulus = larger % smaller;
  }
  return { nominator / smaller, denominator / smaller };
}

using fully_used_slice_counter =
    std::unordered_map<uint64_t, std::unordered_map<uint64_t, std::pair<uint64_t, uint64_t>>>;

auto get_entry( fully_used_slice_counter& slice_counter, uint64_t const& nominator, uint64_t const& denominator )
    -> std::pair<uint64_t, uint64_t>&
{
  auto entry = slice_counter.find( nominator );
  if ( entry == slice_counter.end() )
  {
    auto denominator_map = std::unordered_map<uint64_t, std::pair<uint64_t, uint64_t>>{};
    denominator_map[denominator] = std::make_pair( 0, 0 );
    entry = slice_counter.insert( { nominator, std::move( denominator_map ) } ).first;
  }

  if ( entry->second.count( denominator ) == 0 )
  {
    entry->second[denominator] = std::make_pair( 0, 0 );
  }

  return entry->second[denominator];
}

auto get_least_amount_of_cuts( uint64_t D, std::vector<uint64_t> const& slices ) -> uint64_t
{
  auto maximum_target_slice_size = find_maximum_target_slice_size( D, slices );
  // maximum target slice has to be at least 1, otherwise the algorithm wouldn't even try checking for full cuts
  if ( maximum_target_slice_size == 0 )
  {
    maximum_target_slice_size = 1;
  }

  auto slice_counter = fully_used_slice_counter{};
  for ( auto const& slice : slices )
  {
    for ( auto d = 1U; d <= D; ++d )
    {
      // this will be 0 for floats but, that is okay regarding the below check
      auto slice_size = slice / d;

      if ( slice_size > maximum_target_slice_size )
      {
        continue;
      }

      // won't be fully used, skipping
      if ( slice % d != 0 )
      {
        continue;
      }

      auto [nominator, denominator] = get_reduced_fraction( slice, d );
      auto& entry = get_entry( slice_counter, nominator, denominator );
      // fully using this slice would yield too many total slices, skipping
      if ( entry.first + d > D )
      {
        continue;
      }
      entry.first += d;
      entry.second += 1;
    }
  }

  auto max_fully_used_slice_count = 0U;
  for ( auto const& nominator_entry : slice_counter )
  {
    for ( auto const& denominator_entry : nominator_entry.second )
    {
      if ( denominator_entry.second.second > max_fully_used_slice_count )
      {
        max_fully_used_slice_count = denominator_entry.second.second;
      }
    }
  }

  return D - max_fully_used_slice_count;
}

auto main() -> int
{
  auto test_count = 0;
  std::cin >> test_count;
  for ( int i = 1; i <= test_count; ++i )
  {
    uint64_t N = 0;
    std::cin >> N;
    uint64_t D = 0;
    std::cin >> D;

    auto slices = std::vector<uint64_t>{};
    uint64_t slice_size = 0;
    while ( N > 0 )
    {
      std::cin >> slice_size;

      slices.push_back( slice_size );
      --N;
    }
    std::sort( slices.begin(), slices.end() );
    std::cout << "Case #" << i << ": " << get_least_amount_of_cuts( D, slices ) << std::endl;
  }
  return 0;
}