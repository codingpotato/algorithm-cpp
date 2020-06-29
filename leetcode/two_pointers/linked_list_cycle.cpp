#include <doctest/doctest.h>

#include <memory>
#include <utility>
#include <vector>

#include "list.h"

// 141. Linked List Cycle
class Solution {
 public:
  bool hasCycle(ListNode* head) {
    if (!head) {
      return false;
    }
    auto fast = head;
    auto slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        return true;
      }
    }
    return false;
  }
};

TEST_CASE("Linked list cycle") {
  Solution s;

  SUBCASE("Cycle to middle") {
    List list{3, 2, 0, -4};
    list.make_cycle(1);
    REQUIRE(s.hasCycle(list.head));
  }

  SUBCASE("Cycle to head") {
    List list{1, 2};
    list.make_cycle(0);
    REQUIRE(s.hasCycle(list.head));
  }

  SUBCASE("No cycle") {
    List list{1};
    REQUIRE(!s.hasCycle(list.head));
  }

  SUBCASE("Empty") {
    List list{};
    REQUIRE(!s.hasCycle(list.head));
  }
}
