#include <doctest/doctest.h>

#include <stack>
#include <string>

// 32. Longest Valid Parentheses
int longest_parentheses(const std::string& s) {
  std::stack<int> index_stack;
  std::stack<char> stack;
  auto max = 0;
  index_stack.push(-1);
  for (auto i = 0; i < static_cast<int>(s.size()); ++i) {
    if (stack.empty() || s[i] == '(' || (s[i] == ')' && stack.top() != '(')) {
      index_stack.push(i);
      stack.push(s[i]);
    } else {
      index_stack.pop();
      stack.pop();
      max = std::max(max, i - index_stack.top());
    }
  }
  return max;
}

TEST_CASE("Longest valid parentheses") {
  REQUIRE_EQ(longest_parentheses("((()"), 2);
  REQUIRE_EQ(longest_parentheses(")()())"), 4);
}
