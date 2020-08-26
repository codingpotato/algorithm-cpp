#include <doctest/doctest.h>

#include <vector>

// 80. Remove Duplicates from Sorted Array II
class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    int target = 1;
    int count = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1]) {
        count = 1;
      } else {
        ++count;
      }
      if (count <= 2) {
        nums[target++] = nums[i];
      }
    }
    return target;
  }
};

TEST_CASE("Remove Duplicates from Sorted Array II") {
  Solution s;
  std::vector<int> nums{1, 1, 1, 2, 2, 3};
  REQUIRE_EQ(s.removeDuplicates(nums), 5);
  REQUIRE_EQ(nums, std::vector<int>{1, 1, 2, 2, 3, 3});
}
