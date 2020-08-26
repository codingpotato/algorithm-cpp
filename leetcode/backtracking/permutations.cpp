#include <doctest/doctest.h>

#include <vector>

#include "verify.h"

// 46. Permutations
class Solution {
 public:
  using Result = std::vector<std::vector<int>>;

  Result permute(const std::vector<int>& nums) {
    Result result{{}};
    for (const auto n : nums) {
      result = permute(result, n);
    }
    return result;
  }

 private:
  Result permute(const Result& current, int n) {
    Result result;
    for (const auto& r : current) {
      for (size_t i = 0; i <= r.size(); ++i) {
        std::vector<int> permutation;
        permutation.insert(permutation.end(), r.begin(), r.begin() + i);
        permutation.push_back(n);
        permutation.insert(permutation.end(), r.begin() + i, r.end());
        result.push_back(permutation);
      }
    }
    return result;
  }
};

TEST_CASE("Permutations") {
  Solution s;
  REQUIRE(is_vector_equal_without_order(
      s.permute({1, 2, 3}),
      Solution::Result{
          {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}}));
}
