#include <doctest/doctest.h>

#include <vector>

#include "list.h"
#include "verify.h"

// 19. Remove Nth Node From End of List
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy;
    dummy.next = head;
    auto fast = &dummy;
    while (n > 0) {
      fast = fast->next;
      --n;
    }
    auto slow = &dummy;
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy.next;
  }
};

TEST_CASE("Remove Nth Node From End of List") {
  Solution s;

  SUBCASE("Case 1") {
    List list{1, 2, 3, 4, 5};
    auto head = s.removeNthFromEnd(list.head, 2);
    verify_list(head, std::vector<int>{1, 2, 3, 5});
  }

  SUBCASE("Case 2") {
    List list{1, 2, 3, 4, 5};
    auto head = s.removeNthFromEnd(list.head, 1);
    verify_list(head, std::vector<int>{1, 2, 3, 4});
  }

  SUBCASE("Case 3") {
    List list{1, 2, 3, 4, 5};
    auto head = s.removeNthFromEnd(list.head, 5);
    verify_list(head, std::vector<int>{2, 3, 4, 5});
  }
}
