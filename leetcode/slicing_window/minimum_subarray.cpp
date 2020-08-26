#include <doctest/doctest.h>

#include <climits>
#include <vector>

// 209. Minimum Size Subarray Sum
class Solution {
 public:
  int minSubArrayLen(int s, const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int left = 0;
    int right = 0;
    int sum = nums[0];
    int min_len = INT_MAX;
    while (right < static_cast<int>(nums.size())) {
      if (sum >= s) {
        min_len = std::min(min_len, right - left + 1);
        sum -= nums[left++];
      } else {
        ++right;
        if (right < static_cast<int>(nums.size())) {
          sum += nums[right];
        }
      }
    }
    return min_len == INT_MAX ? 0 : min_len;
  }
};

TEST_CASE("Minimum Size Subarray Sum") {
  Solution s;
  REQUIRE_EQ(s.minSubArrayLen(7, {2, 3, 1, 2, 4, 3}), 2);
  REQUIRE_EQ(s.minSubArrayLen(100, {}), 0);
  REQUIRE_EQ(s.minSubArrayLen(20, {2, 16, 14, 15}), 2);
  REQUIRE_EQ(s.minSubArrayLen(3, {1, 1}), 0);
}
