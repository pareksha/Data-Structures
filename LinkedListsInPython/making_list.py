# Implementing linked list

from linked_list import HeadNode

new_list = HeadNode() # Empty List

# First node
new_list.insert_node(12)
new_list.print_list()

print('-'*15)

# Second node
new_list.insert_node(23)
new_list.print_list()

print('-'*15)

# Third node
new_list.insert_node(10)
new_list.print_list()

print('-'*15)

# Deleting node
new_list.delete_node(12)
new_list.print_list()

print('-'*15)

# Deleting node
new_list.delete_node(23)
new_list.print_list()

print('-'*15)

# Deleting node
new_list.delete_node(10)
new_list.print_list()

print('-'*15)
