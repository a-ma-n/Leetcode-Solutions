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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        int c=0;
        while(fast->next!=NULL && fast->next->next!=NULL){
            c++;
            slow=slow->next;
            fast=fast->next->next;
        }
       // cout<<c<<endl;
        if(fast->next)
         return slow->next;
        else
            return slow;
        
    }
};