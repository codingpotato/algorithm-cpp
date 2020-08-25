#include <doctest/doctest.h>

#include <map>
#include <vector>

std::vector<int> find_numbers(const std::vector<int>& nums) {
  std::map<int, int> map;
  for (const auto n : nums) {
    if (map[n] <= 1)
      map[n] += 1;
    else
      map[n] -= 1;
  }
  std::vector<int> result;
  for (auto& kv : map) {
    if (kv.second == 1) {
      result.push_back(kv.first);
    }
  }
  return result;
}

TEST_CASE("Subarray with given sum") {
  REQUIRE_EQ(find_numbers({1, 2, 3, 2, 1, 4}), std::vector<int>{3, 4});
  REQUIRE_EQ(find_numbers({2, 1, 3, 2}), std::vector<int>{1, 3});
}
