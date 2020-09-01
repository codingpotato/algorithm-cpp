#include <doctest/doctest.h>

#include "list.h"

// 86. Partition List
class Solution {
 public:
  ListNode* partitin(ListNode* head, int x) {
    ListNode left;
    ListNode right;
    ListNode* p_left = &left;
    ListNode* p_right = &right;
    while (head) {
      if (head->val < x) {
        p_left->next = head;
        p_left = p_left->next;
      } else {
        p_right->next = head;
        p_right = p_right->next;
      }
      head = head->next;
    }
    p_left->next = right.next;
    p_right->next = nullptr;
    return left.next;
  }
};

TEST_CASE("Partition List") {
  Solution s;
  List list{1, 4, 3, 2, 5, 2};
  auto head = s.partitin(list.head, 3);
  REQUIRE(is_same(head, std::vector<int>{1, 2, 2, 4, 3, 5}));
}
