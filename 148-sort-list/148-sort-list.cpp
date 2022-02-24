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
    // tail of the new ll
    ListNode* tail = new ListNode();
    // keeps the next list when we deal with the chunks of the list
    ListNode* nextSubList = new ListNode();
    
    // 3 parts -> 1) divide in 2 multiple chunks,2) split to get middle(slow/fast ptr), 3) merge the sorted arrays(create a dummy head and a tail for that)
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next){
           return head;
       }
        // fn to get the length
        int n= getCount(head);
        
        ListNode* start = head;
        ListNode dummyHead(0);
        
        for(int size=1; size<n; size=size*2){
            // we consider multiples of 2 elements per iteration
            tail = &dummyHead;
            while(start){
                if(!start->next){
                    tail->next=start;
                    break;
                }
                //find the middle and split
                ListNode* mid=split(start,size);
                // merge the 2 lists 
                merge(start,mid);
                // make head of next sublist as start and continue this 
                // next sublist is got after splitting
                start = nextSubList;
            }
            start = dummyHead.next;
        }
        
        return dummyHead.next;
    }
    
    ListNode* split(ListNode* start,int size){
        //  apply the concept of finding the middle pointer , by hare and tortoise method, (fast and slow pointers)
        ListNode* midPrev=start;
        ListNode* end=start->next;
     
        for(int index=1;index<size && (midPrev->next || end->next);index++){
            if(end->next){
                // If next to next element exists after end , make end that else make end 
                // the next element so that the condition becomes false in the next iteration
               // at the last iteration. this points to the end of the list(gives us end in both cases  pointed by fast pointer )
                end=(end->next->next) ? end->next->next:end->next;
                }
            if(midPrev->next){
                // slow pointer to get the middle of the list
                midPrev=midPrev->next;
            }
        }
        // if the list was of even length the mid element is the mid+1th element in this case
        // [1234] -> [12] [34], 3 marked as mid and 2 as mid prev
        ListNode* mid = midPrev->next;
        // now the next sublist(global variable) is the sublist after the end pointer
        nextSubList = end->next;
        // To split the lists, make the next of 1st node null &
        //then disconnect last list from the next sublist
        midPrev->next=nullptr;
        end->next=nullptr;
        
        //return the mid (start of 2nd LL)
        return mid;
    }
    
    void merge(ListNode* list1,ListNode* list2){
        //  apply the concept of merging 2 sorted linked lists -> O(n)
        // dummyhead is the head of new ll(so we can put l1 head or l2 head),newTail is tail of the merged ll
        ListNode dummyHead(0);
        ListNode* newTail=&dummyHead;
        while(list1&&list2){
            if(list1->val < list2->val){
                newTail->next = list1;
                list1 = list1->next;
                newTail=newTail->next;
            }else{
                newTail->next=list2;
                list2=list2->next;
                newTail=newTail->next;
            }
        }
        // link to the list that has elements left
        newTail->next= (list1) ? list1:list2;
        // traverse the remaining LL
        while(newTail->next){
            newTail=newTail->next;
        }
        // link old tail (old tail we initialized in main when we ran the for loop), dummyhead.next opints to our first element of merged list
        tail->next=dummyHead.next;
        //update the tail
        tail=newTail;
    }
    
    int getCount(ListNode* head){
        int cnt=0;
        ListNode* ptr = head;
        while(ptr){
            ptr=ptr->next;
            cnt++;
        }
        return cnt;
    }
};