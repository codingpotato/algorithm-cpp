#include <doctest/doctest.h>

#include <set>
#include <string>
#include <vector>

// 784. Letter Case Permutation
class Solution {
 public:
  std::vector<std::string> letterCasePermutation(const std::string& s) {
    std::vector<std::string> result{""};
    for (auto ch : s) {
      auto n = result.size();
      for (auto i = 0; i < n; ++i) {
        if (std::isalpha(ch)) {
          result.push_back(result[i] + static_cast<char>(std::toupper(ch)));
          result[i] += std::tolower(ch);
        } else {
          result[i] += ch;
        }
      }
    }
    return result;
  }
};

bool is_equal(const std::vector<std::string>& lhs,
              const std::vector<std::string>& rhs) {
  return std::set<std::string>{lhs.begin(), lhs.end()} ==
         std::set<std::string>{rhs.begin(), rhs.end()};
}

TEST_CASE("Letter case permutation") {
  Solution s;
  REQUIRE(is_equal(s.letterCasePermutation("a1b2"),
                   {"a1b2", "a1B2", "A1b2", "A1B2"}));
  REQUIRE(is_equal(s.letterCasePermutation("3z4"), {"3z4", "3Z4"}));
  REQUIRE(is_equal(s.letterCasePermutation("12345"), {"12345"}));
  REQUIRE(is_equal(s.letterCasePermutation(""), {""}));
}
