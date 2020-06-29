#include <doctest/doctest.h>

#include "list.h"

// 234. Palindrome Linked List
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    auto fast = head;
    auto slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    auto right_half = slow->next;
    slow->next = nullptr;
    right_half = reverse(right_half);
    while (right_half) {
      if (head->val != right_half->val) {
        return false;
      }
      head = head->next;
      right_half = right_half->next;
    }
    return true;
  }

 private:
  ListNode* reverse(ListNode* head) {
    if (!head->next) {
      return head;
    }
    auto new_head = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
  }
};

TEST_CASE("Palindrome linked list") {
  Solution s;

  SUBCASE("Non palindrome") {
    List list{1, 2};
    REQUIRE(!s.isPalindrome(list.head));
  }

  SUBCASE("Palindrome") {
    List list{1, 2, 2, 1};
    REQUIRE(s.isPalindrome(list.head));
  }
}
