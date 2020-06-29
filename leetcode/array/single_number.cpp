#include <doctest/doctest.h>

#include <vector>

// 136. Single Number
class Solution {
 public:
  int singleNumber(const std::vector<int>& nums) {
    auto result = 0;
    for (auto n : nums) {
      result ^= n;
    }
    return result;
  }
};

TEST_CASE("Single number") {
  Solution s;
  REQUIRE_EQ(s.singleNumber({2, 2, 1}), 1);
  REQUIRE_EQ(s.singleNumber({4, 1, 2, 1, 2}), 4);
}
