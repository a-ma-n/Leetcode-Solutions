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
int lengthOfLinkedList(ListNode* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}
    
    ListNode* reverseKGroup(ListNode* head, int k) {
//         if( head == NULL || k == 1 )
//             return head;
        
//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;
        
//         ListNode * cur = dummy, *nex=dummy,*pre = dummy;
//         int count=0;
        
//         while(cur->next!=NULL){
//             cur=cur->next;
//             count++;
//         }
//         while(count>=k){
//             cur=pre->next;
//             nex=nex->next;
//             for(int i=1;i<k;i++){
//                 cur->next=nex->next;
//                 nex->next=pre->next;
//                 pre->next=nex;
//                 nex=cur->next;
//             }
//             pre=cur;
//             count-=k;
//         }
//         return dummy->next;
          if(head == NULL||head->next == NULL) return head;
    
    int length = lengthOfLinkedList(head);
    
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    
    ListNode* pre = dummyHead;
    ListNode* cur;
    ListNode* nex;
    
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;

    }
};



//         ListNode* startPointer=head;
//         ListNode* endPointer=head;
//         ListNode* tempStart=head;
//         ListNode* tempEnd=head;

        
        
//         int kCount=0;
//         while(endPointer->next!=NULL){
//             kCount++;
            
//             if(kCount==k-1){
//                  tempStart=startPointer;
//             }
//             if(kCount==k){
//                 //reverse
//                  tempEnd=endPointer->next;
//                 ListNode* cur=reverseList(startPointer);
//                 tempStart->next=cur;
//                 while(cur->next!=NULL)
//                     cur=cur->next;
//                 cur->next=tempEnd;
//                 //replace
//                 kCount=0;
//                 startPointer=endPointer->next;
//                 endPointer=endPointer->next;
//             }
//             else{
//                  endPointer=endPointer->next;
//             }
           

//         }
//         return head;
//     ListNode* reverseList(ListNode* head) {
//         ListNode* cur=head;
//         ListNode* prev=NULL;
        
//         while(cur!=NULL ){
//             ListNode* nextNode=cur->next;
//             cur->next=prev;
//             prev=cur;
//             cur=nextNode;
//         }
//         return prev;
//     }