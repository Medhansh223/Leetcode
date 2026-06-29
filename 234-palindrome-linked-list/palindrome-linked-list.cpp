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
    ListNode*rev(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode*newhead=rev(head->next);
        ListNode*front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return true;
        }
        ListNode*temp=head;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*newhead=rev(slow->next);
        slow->next=NULL;
        fast=newhead;
        slow=head;
        while(slow!=NULL && fast!=NULL)
        {
            if(slow->val!=fast->val)
            {
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};