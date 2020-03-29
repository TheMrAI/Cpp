#include <gtest/gtest.h>

#include "hash_map.h"

using namespace mrai;

TEST(hash_map, nothing)
{
  ASSERT_FALSE(true);
  hash_map<int, std::string> lala;
}