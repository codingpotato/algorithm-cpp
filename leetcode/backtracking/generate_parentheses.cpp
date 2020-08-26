#include <doctest/doctest.h>

#include <string>
#include <vector>

// 22. Generate Parentheses
class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> result;
    generateParenthesis(n, 0, 0, 0, "", result);
    return result;
  }

 private:
  void generateParenthesis(int n, int index, int left, int right,
                           std::string current,
                           std::vector<std::string>& result) {
    if (index == n * 2) {
      result.push_back(current);
    }
    if (left < n) {
      generateParenthesis(n, index + 1, left + 1, right, current + "(", result);
    }
    if (left > right) {
      generateParenthesis(n, index + 1, left, right + 1, current + ")", result);
    }
  }
};

TEST_CASE("") {
  Solution s;
  REQUIRE_EQ(s.generateParenthesis(3),
             std::vector<std::string>{"((()))", "(()())", "(())()", "()(())",
                                      "()()()"});
}
