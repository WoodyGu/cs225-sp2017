class TreeNode(object):
    def __init__(self,value):
        self.val = value;
        self.left = None
        self.right = None

def findBST(Node,value):
    if Node == None:
        return False
    elif Node.val == value:
        return True
    elif Node.val < value:
        return findBST(Node.left,value)
    else:
        return findBST(Node.right,value)

n0 = TreeNode(10)
n1 = TreeNode(8)
n2 = TreeNode(13)
n3 = TreeNode(3)
n4 = TreeNode(9)
n5 = TreeNode(16)

n0.left = n1;
n0.right = n2;
n1.left = n3;
n1.right = n4;
n2.left = None;
n2.right = n5;
n3.left = None;
n4.left = None;
n5.left = None;
n3.right = None;
n4.right = None;
n5.right = None;

print findBST(n0,10)
