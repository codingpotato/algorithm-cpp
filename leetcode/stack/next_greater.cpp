#include <doctest/doctest.h>

#include <stack>
#include <vector>

#include "list.h"

// 1019. Next Greater Node In Linked List
class Solution {
 public:
  std::vector<int> nextLargerNodes(ListNode* head) {
    struct Info {
      Info(int index, int value) : index{index}, value{value} {}

      int index;
      int value;
    };

    std::vector<int> result;
    std::stack<Info> stack;
    auto index = 0;
    while (head) {
      while (!stack.empty() && head->val > stack.top().value) {
        set_result(result, stack.top().index, head->val);
        stack.pop();
      }
      stack.emplace(index, head->val);
      ++index;
      head = head->next;
    }
    while (!stack.empty()) {
      set_result(result, stack.top().index, 0);
      stack.pop();
    }
    return result;
  }

 private:
  void set_result(std::vector<int>& result, int index, int value) {
    while (result.size() <= static_cast<size_t>(index)) {
      result.push_back(0);
    }
    result[index] = value;
  }
};

TEST_CASE("Next Greater Node In Linked List") {
  Solution s;

  SUBCASE("Case 1") {
    List list{2, 1, 5};
    REQUIRE_EQ(s.nextLargerNodes(list.head), std::vector<int>{5, 5, 0});
  }

  SUBCASE("Case 2") {
    List list{2, 7, 4, 3, 5};
    REQUIRE_EQ(s.nextLargerNodes(list.head), std::vector<int>{7, 0, 5, 5, 0});
  }

  SUBCASE("Case 3") {
    List list{1, 7, 5, 1, 9, 2, 5, 1};
    REQUIRE_EQ(s.nextLargerNodes(list.head),
               std::vector<int>{7, 9, 9, 9, 0, 5, 0, 0});
  }
}
