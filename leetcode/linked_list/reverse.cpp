#include <doctest/doctest.h>

#include "list.h"

// 206. Reverse Linked List
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* previous = nullptr;
    while (head) {
      auto next = head->next;
      head->next = previous;
      previous = head;
      head = next;
    }
    return previous;
  }
};

TEST_CASE("Reverse Linked List") {
  Solution s;
  List list{1, 2, 3, 4, 5};
  auto head = s.reverseList(list.head);
  auto expected = 5;
  while (head) {
    REQUIRE_EQ(head->val, expected--);
    head = head->next;
  }
  REQUIRE_EQ(expected, 0);
}
