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
        // copy the next nodes value over here, and then delete that node
        node->val = node->next->val;
        node->next = node->next->next;
    }
};