#include <doctest/doctest.h>

#include "list.h"

// 83. Remove Duplicates from Sorted List
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy{0, head};
    auto previous = &dummy;
    auto current = dummy.next;
    while (current) {
      if (previous != &dummy && current->val == previous->val) {
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

TEST_CASE("Remove Duplicates from Sorted List") {
  Solution s;
  List list{1, 1, 2};
  auto head = s.deleteDuplicates(list.head);
  auto expected = 1;
  while (head) {
    REQUIRE_EQ(head->val, expected++);
    head = head->next;
  }
  REQUIRE_EQ(expected, 3);
}

TEST_CASE("Remove Duplicates from Sorted List two duplicates") {
  Solution s;
  List list{1, 1, 2, 3, 3};
  auto head = s.deleteDuplicates(list.head);
  auto expected = 1;
  while (head) {
    REQUIRE_EQ(head->val, expected++);
    head = head->next;
  }
  REQUIRE_EQ(expected, 4);
}
