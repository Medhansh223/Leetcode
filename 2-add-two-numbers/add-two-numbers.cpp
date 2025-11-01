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
        ListNode* temp = new ListNode(-1);
        ListNode* head = temp;
        int sum = 0;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != NULL)
        {
            if(l1 != NULL)
            {
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                sum = sum + l2->val;
                l2 = l2->next;
            }
            sum = sum + carry;
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
            sum = 0;
        }
        return head->next;
    }
};