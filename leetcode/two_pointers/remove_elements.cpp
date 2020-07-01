#include <doctest/doctest.h>

#include "list.h"

// 203. Remove Linked List Elements
class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy{0, head};
    auto previous = &dummy;
    auto current = dummy.next;
    while (current) {
      if (current->val == val) {
        previous->next = current->next;
        current = current->next;
      } else {
        previous = current;
        current = current->next;
      }
    }
    return dummy.next;
  }
};

TEST_CASE("") {
  Solution s;
  List list{1, 2, 6, 3, 4, 5, 6};
  auto head = s.removeElements(list.head, 6);
  auto expected = 1;
  while (head) {
    REQUIRE_EQ(head->val, expected++);
    head = head->next;
  }
  REQUIRE_EQ(expected, 6);
}
