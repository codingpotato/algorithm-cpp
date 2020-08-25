#include <doctest/doctest.h>

#include <algorithm>
#include <set>
#include <vector>

// 15. 3Sum
class Solution {
 public:
  using SetResult = std::set<std::vector<int>>;
  using Result = std::vector<std::vector<int>>;

  Result threeSum(std::vector<int>& nums) {
    SetResult result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        auto sum = nums[left] + nums[right];
        if (sum == -nums[i]) {
          result.insert({nums[i], nums[left], nums[right]});
          ++left;
          --right;
        } else if (sum > -nums[i]) {
          --right;
        } else {
          ++left;
        }
      }
    }
    return Result{result.begin(), result.end()};
  }
};

TEST_CASE("3 Sum") {
  Solution s;
  SUBCASE("Case 1") {
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};
    REQUIRE_EQ(s.threeSum(nums), Solution::Result{{-1, -1, 2}, {-1, 0, 1}});
  }

  SUBCASE("Case 2") {
    std::vector<int> nums{-2, 0, 1, 1, 2};
    REQUIRE_EQ(s.threeSum(nums), Solution::Result{{-2, 0, 2}, {-2, 1, 1}});
  }
}
