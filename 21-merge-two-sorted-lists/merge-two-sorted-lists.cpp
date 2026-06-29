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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* left=list1;
        ListNode* right=list2;
        ListNode* dummy=new ListNode(-1);
        ListNode* newhead=dummy;
        while(left!=NULL && right!=NULL)
        {
            if(left->val<=right->val)
            {
                dummy->next=left;
                dummy=left;
                left=left->next;
            }
            else
            {
                dummy->next=right;
                dummy=right;
                right=right->next;
            }
        }
        while(left!=NULL)
        {
            dummy->next=left;
            dummy=left;
            left=left->next;
        }
        while(right!=NULL)
        {
            dummy->next=right;
            dummy=right;
            right=right->next;
        }
        return newhead->next;
    }
};