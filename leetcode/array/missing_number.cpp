#include <doctest/doctest.h>

#include <vector>

// 268. Missing Number
class Solution {
 public:
  int missingNumber(const std::vector<int>& nums) {
    auto result = nums.size();
    for (size_t i = 0; i < nums.size(); ++i) {
      result ^= i;
      result ^= nums[i];
    }
    return result;
  }

  int missingNumberPlus(const std::vector<int>& nums) {
    auto sum = 0;
    for (auto n : nums) {
      sum += n;
    }
    return nums.size() * (nums.size() + 1) / 2 - sum;
  }
};

TEST_CASE("Missing number") {
  Solution s;
  REQUIRE_EQ(s.missingNumber({3, 0, 1}), 2);
  REQUIRE_EQ(s.missingNumber({9, 6, 4, 2, 3, 5, 7, 0, 1}), 8);
}

TEST_CASE("Missing number plus") {
  Solution s;
  REQUIRE_EQ(s.missingNumberPlus({3, 0, 1}), 2);
  REQUIRE_EQ(s.missingNumberPlus({9, 6, 4, 2, 3, 5, 7, 0, 1}), 8);
}
