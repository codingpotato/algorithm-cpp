#include <doctest/doctest.h>

#include "list.h"
#include "verify.h"

// 25. Reverse Nodes in k-Group
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy;
    auto current = &dummy;
    while (true) {
      auto tail = tail_of_left(head, k);
      if (!tail) {
        current->next = head;
        break;
      }
      auto right = tail->next;
      tail->next = nullptr;
      current->next = reverse(head);
      current = head;
      head = right;
    }
    return dummy.next;
  }

 private:
  ListNode* tail_of_left(ListNode* head, int k) {
    while (k > 1 && head && head->next) {
      head = head->next;
      --k;
    }
    return k == 1 ? head : nullptr;
  }

  ListNode* reverse(ListNode* head) {
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

TEST_CASE("Reverse Nodes in k-Group") {
  Solution s;

  SUBCASE("Case 1") {
    List list{1, 2, 3, 4, 5};
    auto head = s.reverseKGroup(list.head, 2);
    verify_list(head, {2, 1, 4, 3, 5});
  }

  SUBCASE("Case 1") {
    List list{1, 2};
    auto head = s.reverseKGroup(list.head, 2);
    verify_list(head, {2, 1});
  }
}
