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
    ListNode* swapPairs(ListNode* head) {

        // Empty list or only one node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {

            // First and second nodes
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap the two nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev to the end of the swapped pair
            prev = first;
        }

        return dummy->next;
    }
};