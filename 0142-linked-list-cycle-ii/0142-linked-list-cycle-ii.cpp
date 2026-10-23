/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *curl = head;
        unordered_set<ListNode*> lookup ;
        while(curl != nullptr){

            if(lookup.count(curl)){
                return curl;
            }
            lookup.insert(curl);
            curl = curl -> next;
        }
         return nullptr;
    }
};