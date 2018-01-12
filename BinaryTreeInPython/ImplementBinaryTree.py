from BinaryTreeInPython.binaryTree import  *

# Implementing a perfect BST
tree = BST(23)
tree.insert(tree.root, 13)
tree.insert(tree.root, 11)
tree.insert(tree.root, 20)
tree.insert(tree.root, 45)
tree.insert(tree.root, 89)
tree.insert(tree.root, 40)

print('\nPreorder traversal in BST --> ', end='')
tree.print_preorder(tree.root)
print('\nInorder traversal in BST --> ', end='')
tree.print_inorder(tree.root)
print('\nPostorder traversal in BST --> ', end='')
tree.print_postorder(tree.root)

print('\n\nHeight of the BST --> ', tree.find_height(tree.root))
print('Minimum value in the BST -->  ', tree.find_minimum(tree.root))
print('Maximum value in the BST --> ', tree.find_maximum(tree.root))