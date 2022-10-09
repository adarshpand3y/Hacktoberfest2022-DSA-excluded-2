class BinarySearchTree:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
    
    def add_child(self, val):
        if val == self.val:
            return
        if val < self.val:
            if self.left:
                self.left.add_child(val)
            else:
                self.left = BinarySearchTree(val) 
        else:
            if self.right:
                self.right.add_child(val)
            else:
                self.right = BinarySearchTree(val)
    
    def in_order(self):
        elements = []
        #visit left node
        if self.left:
            elements += self.left.in_order()
            
        #visit root node 
        elements.append(self.val)
        
        #visit right node
        if self.right:
            elements += self.right.in_order()        
        return elements
    def post_order(self):
        elements = []
        if self.left:
            elements += self.left.post_order()
        if self.right:
            elements += self.right.post_order()
        elements.append(self.val)
        return elements
    def pre_order(self):
        elements = []
        elements.append(self.val)
        if self.left:
            elements += self.left.post_order()
        if self.right:
            elements += self.right.post_order()
        return elements
    def search(self, val):
        if self.val == val:
            return True
        if val < self.val:
            #val might be in left subtree 
            if self.left:
                return self.left.search(val)
            else:
                return False
        if val > self.val:
            #val might be in right subtree
            if self.right:
                return self.right.search(val)
            else:
                return False
    def find_sum(self):
        sum = 0
        sum += self.val 
        if self.left:
            sum += self.left.find_sum()
        if self.right:
            sum += self.right.find_sum()
        return sum
    
    def find_max(self):
        while self.right:
            self.right.find_max()
        print(self.val)
            
            
    
def build_tree(elements):
    root = BinarySearchTree(elements[0])
    for i in range(1, len(elements)):
        root.add_child(elements[i])
    return root

if __name__ == '__main__':
    elements = [15, 12, 7, 14, 27, 20, 88, 23]
    root = build_tree(elements)
    print(root.in_order())
    print(root.post_order())
    print(root.pre_order())
    print(root.find_max())
    print(root.find_sum())
