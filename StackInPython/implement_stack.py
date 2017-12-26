from stack import Stack

stack_1 = Stack()

print(stack_1.is_empty())

print('-'*15)

stack_1.push(23)
stack_1.push(167)
stack_1.push(45)
stack_1.push(290)
print(stack_1)

print('-'*15)

print(stack_1.is_empty())

print('-'*15)

stack_1.pop()
print(stack_1)

print('-'*15)

stack_1.pop()
print(stack_1)

print('-'*15)