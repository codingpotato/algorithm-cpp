#include <doctest/doctest.h>

#include "list.h"
#include "verify.h"

// 82. Remove Duplicates from Sorted List II

namespace {

class Solution {
 public:
  ListNode* deleteDuplicates1(ListNode* head) {
    ListNode dummy;
    auto current = &dummy;
    while (head) {
      if (!head->next || head->next->val != head->val) {
        current->next = head;
        head = head->next;
        current = current->next;
      } else {
        while (head->next && head->next->val == head->val) {
          head = head->next;
        }
        head = head->next;
      }
    }
    current->next = nullptr;
    return dummy.next;
  }
};

}  // namespace

TEST_CASE("Remove Duplicates from Sorted List II") {
  Solution s;

  SUBCASE("Case 1") {
    List list{1, 2, 3, 3, 4, 4, 5};
    auto head = s.deleteDuplicates1(list.head);
    verify_list(head, {1, 2, 5});
  }
}
