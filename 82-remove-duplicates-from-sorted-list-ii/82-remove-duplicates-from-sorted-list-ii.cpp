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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
                //cout<<"cur:\t"<<cur->val<<"nextNode:\t"<<nextNode->val<<endl;
            return head;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy;
        
        ListNode* cur = head;
        //ListNode* nextNode = head->next;
        
        bool repeat = false;        
        
        // head is null or nead->next is null
        
        
        
        //cout<<"cur:\t"<<cur->val<<"nextNode:\t"<<nextNode->val<<endl;

        while(cur->next!=NULL){ 
         //   cout<<"cur:\t"<<cur->val<<"nextNode:\t"<<nextNode->val<<endl;
            if( cur->val == cur->next->val ){
                repeat = true;
                // prev->next = nextNode->next;
                // cur = prev->next;
                // nextNode = cur->next;
                //                 cout<<"inside :cur:\t"<<cur->val<<"nextNode:\t"<<nextNode->val<<endl;
            cur = cur->next;
            }
            else{
                cur = cur->next;
                
                if(!repeat){
                    pre=pre->next;
                }
                
                pre->next = cur;
                repeat = false;
                
                // prev  = prev -> next;
                // cur = cur -> next;
                // nextNode = nextNode -> next;
            }
        }
        if(repeat)
            pre->next = NULL;
        
        return dummy->next;
        
    }
};