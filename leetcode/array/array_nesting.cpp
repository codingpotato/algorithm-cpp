#include <doctest/doctest.h>

#include <vector>

// 565. Array Nesting
class Solution {
 public:
  int arrayNesting(std::vector<int>& nums) {
    auto index = 0;
    auto max_len = 0;
    auto current_len = 1;
    while (index < static_cast<int>(nums.size())) {
      if (nums[index] != index) {
        std::swap(nums[index], nums[nums[index]]);
        ++current_len;
      } else {
        max_len = std::max(max_len, current_len);
        current_len = 1;
        ++index;
      }
    }
    return max_len;
  }
};

TEST_CASE("Array Nesting") {
  Solution s;
  std::vector<int> nums{5, 4, 0, 3, 1, 6, 2};
  REQUIRE_EQ(s.arrayNesting(nums), 4);
}
