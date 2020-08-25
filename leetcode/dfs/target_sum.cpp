#include <doctest/doctest.h>

#include <cmath>
#include <unordered_map>
#include <vector>

// 494. Target Sum
class Solution {
 public:
  using Table = std::vector<std::unordered_map<int, int>>;

  int findTargetSumWays(const std::vector<int>& nums, int S) {
    Table table{nums.size()};
    return findTargetSumWays(nums, S, 0, 0, table);
  }

 private:
  int findTargetSumWays(const std::vector<int>& nums, int S, int sum, int index,
                        Table& table) {
    if (table[index].find(sum) == table[index].end()) {
      if (index == static_cast<int>(nums.size()) - 1) {
        table[index][sum] =
            (sum + nums[index] == S ? 1 : 0) + (sum - nums[index] == S ? 1 : 0);
      } else {
        table[index][sum] =
            findTargetSumWays(nums, S, sum - nums[index], index + 1, table) +
            findTargetSumWays(nums, S, sum + nums[index], index + 1, table);
      }
    }
    return table[index][sum];
  }
};

TEST_CASE("Target Sum") {
  Solution s;
  REQUIRE_EQ(s.findTargetSumWays({1, 1, 1, 1, 1}, 3), 5);
  REQUIRE_EQ(s.findTargetSumWays({1, 0}, 1), 2);
  REQUIRE_EQ(s.findTargetSumWays(
                 {
                     2, 107, 109, 113, 127, 131, 137, 3,  2,  3,
                     5, 7,   11,  13,  17,  19,  23,  29, 47, 53,
                 },
                 2147483647),
             0);
}
