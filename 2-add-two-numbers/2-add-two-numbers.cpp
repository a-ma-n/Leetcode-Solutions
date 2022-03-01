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
        
        int carry=0,sum=0;
        ListNode* dummyHead=new ListNode(0); 
        ListNode* cur=dummyHead; 
        ListNode* temp=dummyHead;
        
        while(l1!=NULL && l2!=NULL){
            sum=l1->val+l2->val+carry;
            carry=0;
            if(sum>9)
                carry=sum/10;
            temp=new ListNode(sum%10); 
            cout<<temp->val<<endl;
            cur->next=temp;
            cur=cur->next;
            l1=l1->next;
            l2=l2->next;
        }
        cout<<"carry:"<<carry;
        while(l1!=NULL){//l1>l2 in length
            sum=l1->val+carry;
            carry=0;
            temp=new ListNode(sum%10); 
            if(sum>9)
                carry=sum/10;
            l1=l1->next;
            cur->next=temp;
            cur=cur->next;
        }
        while(l2!=NULL){//l1<l2 in length
            sum=l2->val+carry;
            carry=0;
            temp=new ListNode(sum%10); 
            if(sum>9)
                carry=sum/10;
            l2=l2->next;
            cur->next=temp;
            cur=cur->next;
        }
        while(carry>0){
            temp=new ListNode(carry%10);
            carry=carry/10;
            
            cur->next=temp;
            cur=cur->next;
        }
        
        return dummyHead->next;
    }
};