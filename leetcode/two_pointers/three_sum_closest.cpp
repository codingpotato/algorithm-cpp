#include <doctest/doctest.h>

#include <algorithm>
#include <climits>
#include <cmath>
#include <optional>
#include <vector>

// 16. 3Sum Closest
class Solution {
 public:
  int threeSumClosest(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    std::optional<int> min_diff;
    for (size_t i = 0; i < nums.size(); ++i) {
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        auto diff = nums[i] + nums[left] + nums[right] - target;
        if (diff >= 0) {
          --right;
        } else {
          ++left;
        }
        if (!min_diff || std::abs(diff) < std::abs(*min_diff)) {
          min_diff = diff;
        }
      }
    }
    return target + *min_diff;
  }
};

TEST_CASE("3Sum Closest") {
  Solution s;

  SUBCASE("Case 1") {
    std::vector<int> nums{-1, 2, 1, -4};
    REQUIRE_EQ(s.threeSumClosest(nums, 1), 2);
  }

  SUBCASE("Case 2") {
    std::vector<int> nums{0, 0, 0};
    REQUIRE_EQ(s.threeSumClosest(nums, 1), 0);
  }

  SUBCASE("Case 3") {
    std::vector<int> nums{1, 1, 1, 0};
    REQUIRE_EQ(s.threeSumClosest(nums, -100), 2);
  }
};
