class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // 1. Count total nodes properly
        ListNode* temp = head;
        int counter = 0;
        while (temp != nullptr) {
            temp = temp->next;
            counter++;
        }

        // Dummy node helps track the new head of the entire list
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prevGroupTail = &dummy;
        ListNode* curr = head;

        // 2. Process groups while at least k nodes remain
        while (counter >= k) {
            ListNode* groupHead = curr; // Will become the tail after reversal
            ListNode* prev = nullptr;

            // Standard 3-pointer reversal for k nodes
            for (int i = 0; i < k; i++) {
                ListNode* nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp;
            }

            // 3. Reconnect the reversed group to the rest of the list
            prevGroupTail->next = prev; // 'prev' is now the new head of this k-group
            groupHead->next = curr;     // 'curr' is the start of the next group
            
            // Advance prevGroupTail to the end of the group we just reversed
            prevGroupTail = groupHead;
            counter -= k;
        }

        return dummy.next;
    }
};
