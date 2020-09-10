#include <doctest/doctest.h>

#include <vector>

// 338. Counting Bits
class Solution {
 public:
  std::vector<int> countBits(int num) {
    std::vector<int> result(num + 1);
    auto last = 2;
    for (auto i = 0; i <= num; ++i) {
      if (i == 0)
        result[i] = 0;
      else if ((i & (i - 1)) == 0) {
        result[i] = 1;
        last = i;
      } else {
        result[i] = result[i - last] + 1;
      }
    }
    return result;
  }
};

TEST_CASE("") {
  Solution s;
  REQUIRE_EQ(s.countBits(2), std::vector<int>{0, 1, 1});
  REQUIRE_EQ(s.countBits(5), std::vector<int>{0, 1, 1, 2, 1, 2});
}
