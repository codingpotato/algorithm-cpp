#include <doctest/doctest.h>

#include <vector>

// 442. Find All Duplicates in an Array
class Solution {
 public:
  std::vector<int> findDuplicates(std::vector<int>& nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
      auto index = nums[i] - 1;
      while (nums[i] != nums[index]) {
        std::swap(nums[i], nums[index]);
        index = nums[i] - 1;
      }
    }
    std::vector<int> result;
    for (auto i = 0; i < static_cast<int>(nums.size()); ++i) {
      if (nums[i] != i + 1) {
        result.push_back(nums[i]);
      }
    }
    return result;
  }
};

TEST_CASE("Find All Duplicates in an Array") {
  Solution s;
  std::vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
  REQUIRE_EQ(s.findDuplicates(nums), std::vector<int>{3, 2});
}
