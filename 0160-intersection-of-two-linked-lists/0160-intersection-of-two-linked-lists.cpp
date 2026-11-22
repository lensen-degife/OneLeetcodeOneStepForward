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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_set<ListNode*> collections;
        ListNode *pA = headA;
        ListNode *pB = headB;

        while(pA != nullptr){
            collections.insert(pA);
            pA = pA->next;
        }

        while(pB != nullptr){
            if(collections.count(pB)){
                return pB;
            }
            pB = pB->next;
        }
        return nullptr;
        
    }
};