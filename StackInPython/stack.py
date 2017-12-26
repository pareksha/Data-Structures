# Implement Stack using array
class Stack:
    def __init__(self):
        self.stack = list()

    def push(self, data):
        self.stack.append(data)

    def pop(self):
        self.stack.pop()

    def is_empty(self):
        if len(self.stack) == 0:
            return True
        else:
            return False

    def top(self):
        return self.stack[-1]

    def __str__(self):
        return str(self.stack)


class Node:
    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next_node = next_node

    def set_next(self, next=None):
        self.next_node = next

    def get_next(self):
        return self.next_node

    def get_data(self):
        return self.data


# Implement stack using linked list
class LinkedStack:
    def __init__(self):
        self.stack = None

    def push(self, data):
        new_node = Node(data)

        if self.stack is None:
            self.stack = new_node
        else:
            walker = self.stack
            while walker.get_next() is not None:
                walker = walker.get_next()

            walker.set_next(new_node)

    def pop(self):
        if self.stack is None:
            print('Stack is empty')
            return
        pre_walker = None
        walker = self.stack
        while walker.get_next() is not None:
            pre_walker = walker
            walker = walker.get_next()
        pre_walker.set_next(None)

    def is_empty(self):
        if self.stack is None:
            return True
        else:
            return False

    def print_stack(self):
        if self.stack is None:
            print('Stack is empty')
            return
        walker = self.stack
        while walker is not None:
            print(walker.get_data())
            walker = walker.get_next()