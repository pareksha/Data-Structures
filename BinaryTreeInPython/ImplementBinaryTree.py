from BinaryTreeInPython.binaryTree import  *

tree = BST(23)
tree.insert(tree.root, 13)
tree.insert(tree.root, 11)
tree.insert(tree.root, 20)
tree.insert(tree.root, 45)
tree.insert(tree.root, 89)
tree.insert(tree.root, 40)

tree.print_preorder(tree.root)
print()
tree.print_inorder(tree.root)
print()
tree.print_postorder(tree.root)
print()

print(tree.find_height(tree.root))