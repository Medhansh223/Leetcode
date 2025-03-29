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
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }
        int countA = 0;
        ListNode* tempA = headA;
        while(tempA != NULL)
        {
            countA++;
            tempA = tempA->next;
        }
        int countB = 0;
        ListNode* tempB = headB;
        while(tempB != NULL)
        {
            countB++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        int diff = countA - countB;
        if(diff > 0)
        {
            tempA = headA;
            tempB = headB;
            while(diff > 0)
            {
                diff--;
                tempA = tempA->next;
            }
        }
        else
        {
            int newdiff = abs(diff);
            tempA = headA;
            tempB = headB;
            while(newdiff > 0)
            {
                newdiff--;
                tempB = tempB->next;
            }
        }
        while(tempA!=NULL && tempB!=NULL)
        {
            if(tempA == tempB)
            {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};