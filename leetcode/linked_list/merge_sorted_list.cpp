#include <doctest/doctest.h>

#include "list.h"

// 21. Merge Two Sorted Lists
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    auto current = &dummy;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        current->next = l1;
        current = current->next;
        l1 = l1->next;
      } else {
        current->next = l2;
        current = current->next;
        l2 = l2->next;
      }
    }
    if (l1) {
      current->next = l1;
    } else {
      current->next = l2;
    }
    return dummy.next;
  }
};

TEST_CASE("Merge Two Sorted Lists") {
  Solution s;
  List list1{1, 2, 4};
  List list2{1, 3, 4};
  auto head = s.mergeTwoLists(list1.head, list2.head);
  verify_list(head, {1, 1, 2, 3, 4, 4});
}
