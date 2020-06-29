#include <doctest/doctest.h>

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
 public:
  int maxSubArray(const std::vector<int>& nums) {
    auto sum = 0;
    auto max_sum = INT_MIN;
    for (auto n : nums) {
      sum += n;
      sum = std::max(sum, 0);
      max_sum = std::max(max_sum, sum);
    }
    return max_sum;
  }

  int maxSubArrayDivide(const std::vector<int>& nums) {
    return maxSubArrayDivide(nums, 0, nums.size() - 1);
  }

 private:
  int maxSubArrayDivide(const std::vector<int>& nums, int left, int right) {
    if (left == right) {
      return nums[left];
    }
    const auto mid = left + (right - left) / 2;
    const auto result = std::max(maxSubArrayDivide(nums, left, mid),
                                 maxSubArrayDivide(nums, mid + 1, right));
    auto sum_left = 0;
    auto max_sum_left = INT_MIN;
    for (auto i = mid; i >= left; --i) {
      sum_left += nums[i];
      max_sum_left = std::max(max_sum_left, sum_left);
    }
    auto sum_right = 0;
    auto max_sum_right = INT_MIN;
    for (auto i = mid + 1; i <= right; ++i) {
      sum_right += nums[i];
      max_sum_right = std::max(max_sum_right, sum_right);
    }
    return std::max(result, max_sum_left + max_sum_right);
  }
};

TEST_CASE("Max subarray") {
  Solution s;
  REQUIRE_EQ(s.maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
}

TEST_CASE("Max subarray divide") {
  Solution s;
  REQUIRE_EQ(s.maxSubArrayDivide({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
}
