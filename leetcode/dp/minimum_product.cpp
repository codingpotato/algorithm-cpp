#include <doctest/doctest.h>

#include <climits>
#include <vector>

// 152. Maximum Product Subarray
class Solution {
 public:
  int maxProduct(const std::vector<int>& nums) {
    int min = 1;
    int max = 1;
    int max_product = INT_MIN;
    for (const auto n : nums) {
      auto temp_min = std::min(min * n, max * n);
      auto temp_max = std::max(min * n, max * n);
      min = std::min(temp_min, n);
      max = std::max(temp_max, n);
      max_product = std::max(max_product, max);
    }
    return max_product;
  }
};

TEST_CASE("Maximum Product Subarray") {
  Solution s;
  REQUIRE_EQ(s.maxProduct({2, 3, -2, 4}), 6);
  REQUIRE_EQ(s.maxProduct({-2, 0, -1}), 0);
  REQUIRE_EQ(s.maxProduct({2, 3, -2, 8}), 8);
  REQUIRE_EQ(s.maxProduct({-2}), -2);
}
