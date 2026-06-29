/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        if(headA==NULL || headB==NULL)
        {
            return NULL;
        }
        map<ListNode*,int>mpp;
        while(tempA!=NULL)
        {
            mpp[tempA]=1;
            tempA=tempA->next;
        }
        while(tempB!=NULL)
        {
            if(mpp.find(tempB)!=mpp.end())
            {
                return tempB;
            }
            mpp[tempB]=1;
            tempB=tempB->next;
        }
        return NULL;
    }
};