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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(head==NULL)
           return head;
        ListNode *dummy = new ListNode(0); // create a dummy node to mark the head of this list
        dummy->next=head;
        ListNode *pre = dummy; // make a pointer pre as a marker for the node before reversing
        
        for(int i=0 ;i < left-1 ; i++)
            pre = pre->next;
        
        ListNode *start = pre->next; // node of sublist to reverse
        ListNode *then = start->next; // next node to the start (third ptr)
        
        // 1 - 2 -3 - 4 - 5 ; m=2; n =4 ---> pre = 1, start = 2, then = 3
        // dummy-> 1 -> 2 -> 3 -> 4 -> 5
        for(int i = 0 ;i<right-left;i++){
            start->next=then->next;
            then->next=pre->next;
            pre->next=then;
            then = start->next;
        }
    // first reversing : dummy->1 - 3 - 2 - 4 - 5; pre = 1, start = 2, then = 4
    // second reversing: dummy->1 - 4 - 3 - 2 - 5; pre = 1, start = 2, then = 5 (finish) 
        return dummy->next;
    }
};