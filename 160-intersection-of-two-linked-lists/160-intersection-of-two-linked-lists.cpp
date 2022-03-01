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
        // l1-l2 =extraLength => move l1 by extraLength, then check if both next point to same node then true
        ListNode* cur=headA;
        ListNode* l1=headA;
        ListNode* l2=headB;

        int c1=0,c2=0,diff;
        while(cur!=NULL)
        {
            c1++;
            cur=cur->next;
        }
        cur=headB;
        while(cur!=NULL)
        {
            c2++;
            cur=cur->next;
        }
        
        if(c1>c2){
             diff=c1-c2;
            while(diff>0){
                l1=l1->next;
                diff--;
            }
        }
        else{//c2>c1
             diff=c2-c1;
            while(diff>0){
                l2=l2->next;
                diff--;
            }
        }
        
        while(l1!=NULL && l2!=NULL){
            if(l1==l2)
                return l1;
            l1=l1->next;
            l2=l2->next;
        }
        
        
            return NULL;
        
    }
};