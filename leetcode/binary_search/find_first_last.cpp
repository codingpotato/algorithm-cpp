#include <doctest/doctest.h>

#include <vector>

// 34. Find First and Last Position of Element in Sorted Array
class Solution {
 public:
  std::vector<int> searchRange(const std::vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};
    auto left = find_first(nums, target);
    if (left == -1) return {-1, -1};
    return {left, find_last(nums, target, left)};
  }

 private:
  int find_first(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      auto mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return nums[left] == target ? left : -1;
  }

  int find_last(const std::vector<int>& nums, int target, int left) {
    int right = nums.size() - 1;
    while (left < right - 1) {
      auto mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        left = mid;
      } else {
        right = mid - 1;
      }
    }
    return nums[right] == target ? right : left;
  }
};

TEST_CASE("Find First and Last Position of Element in Sorted Array") {
  Solution s;
  REQUIRE_EQ(s.searchRange({5, 7, 7, 8, 8, 10}, 8), std::vector<int>{3, 4});
  REQUIRE_EQ(s.searchRange({5, 7, 7, 8, 8, 10}, 6), std::vector<int>{-1, -1});
  REQUIRE_EQ(s.searchRange({}, 0), std::vector<int>{-1, -1});
}
