"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    def insert(self, head: 'Optional[Node]', insertVal: int) -> 'Node':
        
        
        root=head
        
        if not root: 
            temp=Node(insertVal)
            temp.next=temp
            return temp
        
        while True:
            if root.val <= insertVal <= root.next.val or (root.val > root.next.val and (insertVal >= root.val or insertVal <= root.next.val)) or root.next == head:
                temp = Node(insertVal)
                nextNode = root.next
                root.next = temp
                temp.next = nextNode
                return head
            else:
                root=root.next
                
        return head