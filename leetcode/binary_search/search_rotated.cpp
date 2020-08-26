#include <doctest/doctest.h>

#include <vector>

// 33. Search in Rotated Sorted Array
namespace {

class Solution {
 public:
  int search(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      auto mid = left + (right - left) / 2;
      if (target == nums[mid]) {
        return mid;
      } else if (nums[mid] >= nums[left]) {
        if (target >= nums[left] && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else if (nums[mid] <= nums[right]) {
        if (target > nums[mid] && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return -1;
  }
};

}  // namespace

TEST_CASE("Search in Rotated Sorted Array") {
  Solution s;
  REQUIRE_EQ(s.search({4, 5, 6, 7, 0, 1, 2}, 0), 4);
  REQUIRE_EQ(s.search({4, 5, 6, 7, 0, 1, 2}, 3), -1);
  REQUIRE_EQ(s.search({1}, 0), -1);
}
