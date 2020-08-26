#include <doctest/doctest.h>

#include "list.h"
#include "verify.h"

// 92. Reverse Linked List II
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    auto count = n - m + 1;
    ListNode dummy{0, head};
    auto current = &dummy;
    while (m > 1) {
      current = current->next;
      --m;
    }
    ListNode* mid = nullptr;
    auto tail = current->next;
    auto p = current->next;
    current->next = nullptr;
    while (count > 0) {
      auto next = p->next;
      p->next = mid;
      mid = p;
      p = next;
      --count;
    }
    current->next = mid;
    tail->next = p;
    return dummy.next;
  }
};

TEST_CASE("Reverse Linked List II") {
  Solution s;
  List list{1, 2, 3, 4, 5};
  auto head = s.reverseBetween(list.head, 2, 4);
  verify_list(head, {1, 4, 3, 2, 5});
}
