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
    ListNode* removeElements(ListNode* head, int val) {

        if (!head) return head;

        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;

        while (current != NULL)
        {
            next = current->next;

            if (current->val == val)
            {
                if (prev == NULL)
                {
                    current = next;
                    head = next;
                }
                else
                {
                    prev->next = next;
                    current = next;
                }
            }
            else
            {
                prev = current;
                current = next;
            }

        }



        return head;
    }
};