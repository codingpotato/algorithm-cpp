#include <doctest/doctest.h>

#include <vector>

// 238. Product of Array Except Self
class Solution {
 public:
  std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    std::vector<int> result;
    auto product = 1;
    for (const auto n : nums) {
      product *= n;
      result.push_back(product);
    }
    product = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      result[i] = (i > 0 ? result[i - 1] : 1) * product;
      product *= nums[i];
    }
    return result;
  }
};

TEST_CASE("Product of Array Except Self") {
  Solution s;
  REQUIRE_EQ(s.productExceptSelf({1, 2, 3, 4}), std::vector<int>{24, 12, 8, 6});
}
