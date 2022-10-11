'''
Given a binary tree, determine if it is height-balanced.

For this, a height-balanced binary tree is defined as:
- a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
'''

class Solution:
    def height(self, root):  #helper function
        if root is None:
            return 0
        hl = self.height(root.left)
        hr = self.height(root.right)
        return 1+max(hl, hr)
        
    def isBalanced(self, root):
        if root is None:
          return True
        
        lh= self.height(root.left)
        rh= self.height(root.right)
        if lh-rh>1 or rh-lh>1:
          return False
        isleft_balance=self.isBalanced(root.left)
        isright_balance=self.isBalanced(root.right)
        if isleft_balance and isright_balance:
          return True
        return False
