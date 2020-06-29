#include <doctest/doctest.h>

#include <set>
#include <vector>

// 217. Contains Duplicate
class Solution {
 public:
  bool containsDuplicate(const std::vector<int>& nums) {
    std::set<int> s;
    for (auto n : nums) {
      s.insert(n);
    }
    return s.size() != nums.size();
  }
};

TEST_CASE("Contains duplicate") {
  Solution s;
  REQUIRE(s.containsDuplicate({1, 2, 3, 1}));
  REQUIRE(!s.containsDuplicate({1, 2, 3, 4}));
  REQUIRE(s.containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}));
}
