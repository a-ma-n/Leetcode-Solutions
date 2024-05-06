# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ptr=head
        cur=head
        l=[]
        
        
        
        while ptr:
            l.append(ptr.val)
            ptr=ptr.next
        
        print(l)
        ans=[]
        
        #duplicate elements
        notSame=False
        firstElement=head.val
        for i in range(1,len(l)):
            if l[i]!=firstElement:
                notSame=True
                break 
        if not notSame:
            return head
            
        
        for i in reversed(l):
            if not ans:
                ans.append(i)
            elif i>ans[-1] or i == ans[-1]:
                ans.append(i)
        ans=ans[::-1]
        print(ans)
        
        dummy=ListNode(0)
        
        cur2=dummy
        i=0
        # seen=[]
        cur=head
        while cur:
            # print(i,cur.val,ans[i])
            if i<len(ans) and cur.val==ans[i] :
                cur2.next=cur
                cur2=cur2.next
                i+=1
                # seen.append(cur.val)
            cur=cur.next
        # print(seen)
        return dummy.next
        