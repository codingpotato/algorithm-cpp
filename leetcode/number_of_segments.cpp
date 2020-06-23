#include <doctest/doctest.h>

#include <algorithm>
#include <string>

// 434. Number of Segments in a String
class Solution {
 public:
  int countSegments(const std::string& s) {
    auto index = 0;
    auto count = 0;
    while (index < s.size()) {
      while (index < s.size() && s[index] == ' ') {
        ++index;
      }
      if (index < s.size() && s[index] != ' ') {
        ++count;
      }
      while (index < s.size() && s[index] != ' ') {
        ++index;
      }
    }
    return count;
  }
};

TEST_CASE("Number of segments") {
  Solution s;
  REQUIRE_EQ(s.countSegments("Hello, my name is John"), 5);
}

TEST_CASE("Number of segments with empty string") {
  Solution s;
  REQUIRE_EQ(s.countSegments(""), 0);
}

TEST_CASE("Number of segments with only space") {
  Solution s;
  REQUIRE_EQ(s.countSegments("       "), 0);
}
