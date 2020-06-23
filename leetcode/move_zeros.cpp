#include <doctest/doctest.h>

#include <vector>

// 283. Move Zeroes
class Solution {
 public:
  void moveZeroes(std::vector<int>& nums) {
    auto target = 0;
    for (auto i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        nums[target++] = nums[i];
      }
    }
    for (auto i = target; i < nums.size(); ++i) {
      nums[i] = 0;
    }
  }
};

TEST_CASE("Move Zeroes") {
  std::vector<int> nums{0, 1, 0, 3, 12};
  Solution s;
  s.moveZeroes(nums);
  REQUIRE_EQ(nums, std::vector{1, 3, 12, 0, 0});
}
