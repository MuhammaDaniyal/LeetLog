/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        Node* curr = head;

        while (curr)
        {
            if (curr->next == NULL && curr->child == NULL)
                return head;
            else if (curr->child != NULL)
            {
                Node* next = curr->next;
                Node* wow = flatten(curr->child);

                curr->next = wow;
                wow->prev = curr;
                curr->child = NULL;

                if (next != NULL) {
                    while (wow->next)
                        wow = wow->next;
                    wow->next = next;
                    next->prev = wow;
                    curr = next;
                }
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};