#include <doctest/doctest.h>

#include "list.h"

// 206. Reverse Linked List
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* result = nullptr;
    while (head) {
      auto next = head->next;
      head->next = result;
      result = head;
      head = next;
    }
    return result;
  }
};

TEST_CASE("Reverse Linked List") {
  Solution s;
  List list{1, 2, 3, 4, 5};
  auto head = s.reverseList(list.head);
  verify_list(head, {5, 4, 3, 2, 1});
}
