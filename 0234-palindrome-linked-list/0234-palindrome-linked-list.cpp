/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* cur = slow;
        ListNode* prev = nullptr;

        while(cur != nullptr){
            ListNode* next_temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next_temp;
        }
        ListNode* right = prev;
        ListNode* left = head;
        while(right != nullptr){
            if(right->val != left->val){
                return false;
            }
            right = right->next;
            left = left->next;
        }
        return true;

    }
};