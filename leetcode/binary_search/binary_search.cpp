#include <doctest/doctest.h>

#include <vector>

// 704. Binary Search
class Solution {
 public:
  int search(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      auto mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};

TEST_CASE("Binary search") {
  Solution s;
  REQUIRE_EQ(s.search({-1, 0, 3, 5, 9, 12}, 9), 4);
  REQUIRE_EQ(s.search({-1, 0, 3, 5, 9, 12}, 2), -1);
  REQUIRE_EQ(s.search({5}, -5), -1);
}
