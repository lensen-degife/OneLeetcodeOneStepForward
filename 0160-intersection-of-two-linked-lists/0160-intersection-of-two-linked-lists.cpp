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
        
        unordered_set<ListNode* > collection;

        ListNode* currentPtr= headA;
        while(currentPtr != nullptr){
            collection.insert(currentPtr);
            currentPtr=currentPtr->next;
        }
        ListNode* ptrB = headB;

        while(ptrB != nullptr){
            if(collection.count(ptrB)){
                return ptrB;
            }
            ptrB = ptrB->next;
        }

    return nullptr;

    }
};