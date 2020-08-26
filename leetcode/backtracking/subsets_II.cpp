#include <doctest/doctest.h>

#include <algorithm>
#include <set>
#include <vector>

#include "verify.h"

// 90. Subsets II
namespace {

class Solution {
 public:
  using Result = std::vector<std::vector<int>>;
  using ResultSet = std::set<std::vector<int>>;

  Result subsetsWithDup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    ResultSet result{{}};
    for (const auto& n : nums) {
      subsets(result, n);
    }
    return Result{result.begin(), result.end()};
  }

 private:
  void subsets(ResultSet& result, int n) {
    auto temp = result;
    for (auto set : temp) {
      set.push_back(n);
      result.insert(set);
    }
  }
};

}  // namespace

TEST_CASE("Subsets") {
  Solution s;
  std::vector<int> nums{1, 2, 2};
  REQUIRE(is_vector_equal_without_order(
      s.subsetsWithDup(nums),
      Solution::Result{{2}, {1}, {1, 2, 2}, {2, 2}, {1, 2}, {}}));
}
