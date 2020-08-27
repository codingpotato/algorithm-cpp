#include <doctest/doctest.h>

#include <vector>

std::pair<int, int> subarray_given_sum(const std::vector<int>& nums, int sum) {
  size_t left = 0;
  size_t right = 0;
  auto current_sum = nums[0];
  while (right < nums.size()) {
    if (current_sum == sum) {
      return {left + 1, right + 1};
    } else if (current_sum < sum) {
      ++right;
      current_sum += nums[right];
    } else {
      current_sum -= nums[left];
      ++left;
    }
  }
  return {0, 0};
}

TEST_CASE("Subarray with given sum") {
  REQUIRE_EQ(subarray_given_sum({1, 2, 3, 7, 5}, 12),
             std::pair<int, int>{2, 4});
  REQUIRE_EQ(subarray_given_sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 15),
             std::pair<int, int>{1, 5});
  REQUIRE_EQ(subarray_given_sum({1, 2, 10}, 10), std::pair<int, int>{3, 3});
}
