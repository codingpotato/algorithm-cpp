#include <doctest/doctest.h>

#include <map>
#include <vector>

// 560. Subarray Sum Equals K
class Solution {
 public:
  int subarraySum(const std::vector<int>& nums, int k) {
    std::map<int, int> table;
    table[0] = 1;
    auto total = 0;
    auto sum = 0;
    for (const auto& n : nums) {
      sum += n;
      if (table.find(sum - k) != table.end()) {
        total += table[sum - k];
      }
      ++table[sum];
    }
    return total;
  }
};

TEST_CASE("Subarray Sum Equals K") {
  Solution s;
  REQUIRE_EQ(s.subarraySum({1, 1, 1}, 2), 2);
  REQUIRE_EQ(s.subarraySum({0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0), 55);
}
