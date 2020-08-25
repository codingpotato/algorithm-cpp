#include <doctest/doctest.h>

#include <map>
#include <vector>

// 1. Two Sum
class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::map<int, int> table;
    for (auto i = 0; i < static_cast<int>(nums.size()); ++i) {
      auto value = target - nums[i];
      if (table.find(value) != table.end()) {
        return {table[value], i};
      }
      table[nums[i]] = i;
    }
    return {0, 0};
  }
};

TEST_CASE("Two sum") {
  Solution s;
  REQUIRE_EQ(s.twoSum({2, 7, 11, 15}, 9), std::vector<int>{0, 1});
}
