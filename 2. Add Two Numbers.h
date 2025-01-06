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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        int sum = 0;
        ListNode* l1Copy = l1;
        ListNode* l2Copy = l2;
        ListNode* result = NULL;
        ListNode* returnResult;
        ListNode* previous;

        while (l1 && l2)
        {
            l1 = l1->next;
            l2 = l2->next;

            if (!l1)         result = l2Copy;
            else if (!l2)    result = l1Copy;
        }
        l1 = l1Copy;
        l2 = l2Copy;
        returnResult = result;

        while (result != NULL)
        {
            if (!l1)
            {
                sum = l2->val + carry;
                l2 = l2->next;
            }
            else if (!l2)
            {
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else
            {
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }

            if (sum > 9)     carry = sum / 10;
            else            carry = 0;
            sum = sum % 10;

            result->val = sum;
            previous = result;
            result = result->next;
        }

        if (carry == 1)
            previous->next = new ListNode(carry);


        return returnResult;
    }
};