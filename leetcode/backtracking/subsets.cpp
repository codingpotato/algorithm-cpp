#include <doctest/doctest.h>

#include <vector>

#include "verify.h"

// 78. Subsets
class Solution {
 public:
  using Result = std::vector<std::vector<int>>;

  Result subsets(const std::vector<int>& nums) {
    Result result{{}};
    for (const auto& n : nums) {
      subsets(result, n);
    }
    return result;
  }

 private:
  void subsets(Result& result, int n) {
    const auto size = result.size();
    for (size_t i = 0; i < size; ++i) {
      std::vector<int> set = result[i];
      set.push_back(n);
      result.push_back(set);
    }
  }
};

TEST_CASE("Subsets") {
  Solution s;
  REQUIRE(is_vector_equal_without_order(
      s.subsets({1, 2, 3}),
      Solution::Result{{3}, {1}, {2}, {1, 2, 3}, {1, 3}, {2, 3}, {1, 2}, {}}));
}
