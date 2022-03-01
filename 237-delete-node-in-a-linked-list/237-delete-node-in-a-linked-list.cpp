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
    void deleteNode(ListNode* node) {
        
        ListNode* nodeNext=node->next;
        
        while(nodeNext->next!=NULL){
            node->val=nodeNext->val;
            node=node->next;
            nodeNext=nodeNext->next;
        }
        node->val=nodeNext->val;
        node->next=NULL;
    }
};