#include <doctest/doctest.h>

#include <vector>

// 41. First Missing Positive
class Solution {
 public:
  int firstMissingPositive(std::vector<int>& nums) {
    auto i = 0;
    while (i < static_cast<int>(nums.size())) {
      if (nums[i] != i + 1) {
        if (nums[i] > 0 && nums[i] <= static_cast<int>(nums.size()) &&
            nums[i] != nums[nums[i] - 1]) {
          std::swap(nums[i], nums[nums[i] - 1]);
          continue;
        }
      }
      ++i;
    }
    for (auto i = 0; i < static_cast<int>(nums.size()); ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }
};

TEST_CASE("First Missing Positive") {
  Solution s;

  SUBCASE("Case 1") {
    std::vector<int> nums{1, 2, 0};
    REQUIRE_EQ(s.firstMissingPositive(nums), 3);
  }

  SUBCASE("Case 2") {
    std::vector<int> nums{3, 4, -1, 1};
    REQUIRE_EQ(s.firstMissingPositive(nums), 2);
  }

  SUBCASE("Case 3") {
    std::vector<int> nums{7, 8, 9, 11, 12};
    REQUIRE_EQ(s.firstMissingPositive(nums), 1);
  }

  SUBCASE("Case 4") {
    std::vector<int> nums{2147483647, 2147483646, 2147483645, 3,          2,
                          1,          -1,         0,          -2147483648};
    REQUIRE_EQ(s.firstMissingPositive(nums), 4);
  }
}
