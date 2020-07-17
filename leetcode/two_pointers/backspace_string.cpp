#include <doctest/doctest.h>

#include <string>

// 844. Backspace String Compare
class Solution {
 public:
  bool backspaceCompare(std::string S, std::string T) {
    auto length_s = backspace(S);
    auto length_t = backspace(T);
    if (length_s != length_t) {
      return false;
    }
    for (auto i = 0; i < length_s; ++i) {
      if (S[i] != T[i]) {
        return false;
      }
    }
    return true;
  }

 private:
  int backspace(std::string& s) {
    int dest = 0;
    for (auto i = 0; i < s.size(); ++i) {
      if (s[i] == '#') {
        if (dest > 0) {
          --dest;
        }
      } else {
        s[dest++] = s[i];
      }
    }
    return dest;
  }
};

TEST_CASE("Backspace string compare") {
  Solution s;
  REQUIRE(s.backspaceCompare("ab#c", "ad#c"));
  REQUIRE(s.backspaceCompare("ab##", "c#d#"));
  REQUIRE(s.backspaceCompare("a##c", "#a#c"));
  REQUIRE_FALSE(s.backspaceCompare("a#c", "b"));
}
