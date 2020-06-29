#include <doctest/doctest.h>

#include <vector>

// 198. House Robber
class Solution {
 public:
  int rob(const std::vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    auto max_prev = nums[0];
    auto max_current = std::max(nums[0], nums[1]);
    for (auto i = 2; i < nums.size(); ++i) {
      auto next = std::max(max_prev + nums[i], max_current);
      max_prev = max_current;
      max_current = next;
    }
    return max_current;
  }
};

TEST_CASE("House robber") {
  Solution s;
  REQUIRE_EQ(s.rob({1, 2, 3, 1}), 4);
  REQUIRE_EQ(s.rob({2, 7, 9, 3, 1}), 12);
}
