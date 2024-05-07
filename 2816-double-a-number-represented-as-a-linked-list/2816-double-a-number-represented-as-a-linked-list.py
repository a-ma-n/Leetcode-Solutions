# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        def length(n):
            l=0
            while n>0:
                l+=1
                n//=10
            return l
        
        num=0
        root=head
        while root:
            num=num*10+root.val
            root=root.next
        
        num*=2
        l=length(num)
        
        root=head
        k=0
        if l==1:
            dr=1
        else:
            dr=1*(10**(l-1))
        
        # n=len(num)
        prev=ListNode(0)
        prev.next=head
        
        while root:
                root.val=int(num//dr)
                num%=dr
                dr//=10
                prev=root
                root=root.next
                
        while dr>0:
            print(num,dr)
            prev.next=ListNode(num//dr)
            prev=prev.next
            num%=dr
            dr//=10
            # num//=10
            l-=1
        
        return head

    
    