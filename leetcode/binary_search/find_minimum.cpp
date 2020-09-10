#include <doctest/doctest.h>

#include <vector>

// 153. Find Minimum in Rotated Sorted Array
namespace {

class Solution {
 public:
  int findMin(const std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (nums[left] > nums[right]) {
      auto mid = left + (right - left) / 2;
      if (nums[mid] >= nums[left]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return nums[left];
  }
};

}  // namespace

TEST_CASE("Find Minimum in Rotated Sorted Array") {
  Solution s;
  REQUIRE_EQ(s.findMin({3, 4, 5, 1, 2}), 1);
  REQUIRE_EQ(s.findMin({4, 5, 6, 7, 0, 1, 2}), 0);
  REQUIRE_EQ(s.findMin({3, 0, 1, 2}), 0);
  REQUIRE_EQ(s.findMin({3, 0, 1}), 0);
  REQUIRE_EQ(s.findMin({2, 3, 0, 1}), 0);
  REQUIRE_EQ(s.findMin({1, 2, 3, 0}), 0);
}
