# Node class defines an element of the linked list
class Node:
    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next_node = next_node

    def get_data(self):
        return self.data

    def get_next_node(self):
        return self.next_node

    def set_next_node(self, new_next=None):
        self.next_node = new_next


# Creates list
class HeadNode:
    def __init__(self, head_node=None):
        self.head = head_node

    def get_list_name(self):
        return self.head

    def search_node_by_value(self, data_target):
        pre = None
        cur = self.head
        flag = False
        while cur is not None:
            if cur.get_data() == data_target:
                flag = True
                break
            elif cur.get_data() < data_target:
                pre = cur
                cur = cur.get_next_node()
            else:
                break
        return flag, cur, pre

    def delete_node(self, data_target):
        if self.head is None:
            print('List is empty')
        else:
            flag, cur, pre = self.search_node_by_value(data_target)
            if flag is True and pre is None:
                self.head = cur.get_next_node()
            elif flag is True and pre is not None and cur is not None:
                pre.set_next_node(cur.get_next_node())
            elif flag is True and cur.get_next_node() is None:
                pre.set_next_node(None)
            else:
                print('Element not present in the list !')

    def insert_node(self, data):
        new_node = Node(data)
        flag, cur, pre = self.search_node_by_value(data)
        if flag is False and pre is None:
            new_node.set_next_node(self.head)
            self.head = new_node
        elif flag is False and cur is None:
            new_node.set_next_node(None)
            pre.set_next_node(new_node)
        elif flag is False and pre is not None and cur is not None:
            new_node.set_next_node(cur)
            pre.set_next_node(new_node)
        else:
            print('Entered value is already present in the list.')

    def print_list(self):
        if self.head is None:
            print('List is empty')
        else:
            walker = self.head
            while walker is not None:
                print(walker.get_data())
                walker = walker.get_next_node()
