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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp1 = head;
        ListNode* temp2 = head;
        ListNode* prev = nullptr;

        if (!head || !head->next)
            return head;


        while (temp1 != nullptr)
        {
            while (temp2 != nullptr)
            {
                if (temp1 != temp2 && temp1->val == temp2->val)
                {
                    temp2 = temp2->next;
                    prev->next = temp2;
                    continue;
                }
                prev = temp2;
                temp2 = temp2->next;
            }
            prev = nullptr;
            temp2 = head;
            temp1 = temp1->next;
        }

        return head;

    }
};