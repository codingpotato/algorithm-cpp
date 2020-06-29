#include <doctest/doctest.h>

#include <vector>

class Solution {
 public:
  std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    auto index = 0;
    while (index < nums.size()) {
      auto target = nums[index] - 1;
      if (target != index && nums[index] != nums[target]) {
        std::swap(nums[index], nums[target]);
      } else {
        ++index;
      }
    }
    std::vector<int> result;
    for (auto index = 0; index < nums.size(); ++index) {
      if (nums[index] - 1 != index) {
        result.push_back(index + 1);
      }
    }
    return result;
  }
};

TEST_CASE("Find all numbers") {
  Solution s;
  std::vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
  REQUIRE_EQ(s.findDisappearedNumbers(nums), std::vector<int>{5, 6});
}
