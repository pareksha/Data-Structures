class TreeNode(object):
    def __init__(self, data=None):
        self.data = data
        self.right_child = None
        self.left_child = None


class BST(object):
    def __init__(self, root_value):
        self.root = TreeNode(root_value)

    def insert(self, root, value):
        if root is None:
            return TreeNode(value)

        elif root.data >= value:
            root.left_child = self.insert(root.left_child, value)
            return root

        else:
            root.right_child = self.insert(root.right_child, value)
            return root

    def print_preorder(self, root):
        if root is None:
            return
        print(root.data, end='    ')
        self.print_preorder(root.left_child)
        self.print_preorder(root.right_child)

    def print_inorder(self, root):
        if root is None:
            return
        self.print_inorder(root.left_child)
        print(root.data, end='    ')
        self.print_inorder(root.right_child)

    def print_postorder(self, root):
        if root is None:
            return
        self.print_postorder(root.left_child)
        self.print_postorder(root.right_child)
        print(root.data, end='    ')

    def find_height(self, root):
        if root is None:
            return -1
        else:
            return max(self.find_height(root.left_child), self.find_height(root.right_child)) + 1

    def find_minimum(self, root):
        if root.left_child is None:
            return root.data
        else:
            return self.find_minimum(root.left_child)

    def find_maximum(self, root):
        if root.right_child is None:
            return root.data
        else:
            return self.find_maximum(root.right_child)

    def find_depth(self, value, root, depth=0):
        if root is None:
            return 'Node with value ' + str(value) + ' not present  in the BST with root ' + str(root)
        elif root.data == value:
            return depth
        elif value < root.data:
            return self.find_depth(value, root.left_child, depth=depth + 1)
        else:
            return self.find_depth(value, root.right_child, depth=depth + 1)

    def delete(self, value, root):
        # Delete node with no left or right child
        if root.right_child.data == value and root.right_child.right_child is None and root.right_child.left_child is None:
            root.right_child = None
        elif root.left_child.data == value and root.left_child.left_child is None and root.left_child.right_child is None:
            root.left_child = None

        # Delete node with both left and right child
        elif root.right_child.data == value and root.right_child.left_child is not None and root.right_child.right_child is not None:
            minimum_value = self.find_minimum(root.right_child.right_child)
            root.right_child.data = minimum_value
            print('Hey')
            self.delete(minimum_value, root.right_child)

        elif root.left_child.data == value and root.left_child.left_child is not None and root.left_child.right_child is not None:
            minimum_value = self.find_minimum(root.left_child.right_child)
            root.left_child.data = minimum_value
            self.delete(minimum_value, root.left_child)

        # Delete node with either left or right child
        elif root.left_child.data == value:
            node_to_be_deleted = root.left_child
            if root.left_child.left_child is None and root.left_child.right_child is not None:
                root.left_child = root.left_child.right_child
                root.left_child.right_child = None
            elif root.left_child.left_child is not None and root.left_child.right_child is None:
                root.left_child = root.left_child.left_child
                root.left_child.left_child = None
            del node_to_be_deleted
        elif root.right_child.data == value:
            node_to_be_deleted = root.right_child
            if root.right_child.left_child is None and root.right_child.right_child is not None:
                root.right_child = root.right_child.right_child
                root.right_child.right_child = None
            elif root.right_child.left_child is not None and root.right_child.right_child is None:
                root.right_child = root.right_child.left_child
                root.right_child.left_child = None
            del node_to_be_deleted

        elif value < root.data:
            self.delete(value, root.left_child)
        elif value > root.data:
            self.delete(value, root.right_child)