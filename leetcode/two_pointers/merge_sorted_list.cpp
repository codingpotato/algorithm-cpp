#include <doctest/doctest.h>

#include "list.h"

// 21. Merge Two Sorted Lists
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    auto node = &dummy;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        node->next = l1;
        node = l1;
        l1 = l1->next;
      } else {
        node->next = l2;
        node = l2;
        l2 = l2->next;
      }
    }
    while (l1) {
      node->next = l1;
      node = l1;
      l1 = l1->next;
    }
    while (l2) {
      node->next = l2;
      node = l2;
      l2 = l2->next;
    }
    return dummy.next;
  }
};

TEST_CASE("Merge two sorted lists") {
  Solution s;
  List list1{1, 2, 4};
  List list2{1, 3, 4};

  auto head = s.mergeTwoLists(list1.head, list2.head);

  List expected{1, 1, 2, 3, 4, 4};
  auto expected_head = expected.head;
  while (head && expected_head) {
    REQUIRE_EQ(head->val, expected_head->val);
    head = head->next;
    expected_head = expected_head->next;
  }
  REQUIRE(!expected_head);
}
