#include <doctest/doctest.h>

#include <set>
#include <vector>

// 287. Find the Duplicate Number
class Solution {
 public:
  int findDuplicate(const std::vector<int>& nums) {
    std::set<int> s;
    for (auto n : nums) {
      if (s.find(n) == s.end()) {
        s.insert(n);
      } else {
        return n;
      }
    }
    return -1;
  }
};

TEST_CASE("Find the Duplicate Number") {
  Solution s;
  REQUIRE_EQ(s.findDuplicate({1, 3, 4, 2, 2}), 2);
  REQUIRE_EQ(s.findDuplicate({3, 1, 3, 4, 2}), 3);
  REQUIRE_EQ(s.findDuplicate({2, 2, 2, 2, 2}), 2);
}
