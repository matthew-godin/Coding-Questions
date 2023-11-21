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
private:
    void advanceNode(ListNode **currentPtr, ListNode *nextNode) {
        (*currentPtr)->next = nextNode;
        *currentPtr = nextNode;
    }

    void setVal(ListNode **currentPtr, int sum, int *carry) {
        if (sum > 9) {
            (*currentPtr)->val = sum - 10;
            *carry = 1;
        } else {
            (*currentPtr)->val = sum;
            *carry = 0;
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *currentPtr = new ListNode();
        ListNode *nextNode = result;
        int carry = 0;
        for (;;) {
            if (l1 == nullptr) {
                if (l2 == nullptr) {
                    if (carry == 1) {
                        advanceNode(&currentPtr, nextNode);
                        currentPtr->val = 1;
                    }
                    return result;
                }
                advanceNode(&currentPtr, nextNode);
                int sum = l2->val + carry;
                setVal(&currentPtr, sum, &carry);
                l2 = l2->next;
            } else {
                advanceNode(&currentPtr, nextNode);
                if (l2 == nullptr) {
                    int sum = l1->val + carry;
                    setVal(&currentPtr, sum, &carry);
                } else {
                    int sum = l1->val + l2->val + carry;
                    setVal(&currentPtr, sum, &carry);
                    l2 = l2->next;
                }
                l1 = l1->next;
            }
            nextNode = new ListNode();
        }
    }
};