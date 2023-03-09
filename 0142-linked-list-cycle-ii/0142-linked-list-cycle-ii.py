# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, root: Optional[ListNode]) -> Optional[ListNode]:
        if not root: return None
        head=tail=root
        temp=None
        while head.next is not None and head.next.next is not None:

            head=head.next.next
            tail=tail.next
            if head==tail:
                temp=root
                break
        if not temp: return None
        # i=0
        print(temp.val)
        while temp!=head:
            # i+=1
            head=head.next
            temp=temp.next
        return temp
        
        
        