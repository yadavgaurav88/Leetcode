class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        // Move prev to the node before 'left'
        for (int i = 1; i < left; i++)
            prev = prev->next;

        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* prevNode = nullptr;

        // Reverse the sublist
        for (int i = left; i <= right; i++) {
            next = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = next;
        }

        // Reconnect
        ListNode* tail = prev->next;

        prev->next = prevNode;
        tail->next = curr;

        return dummy->next;
    }
};