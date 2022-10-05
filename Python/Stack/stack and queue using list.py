# (a) To implement stack using list.

# Initializing a list
list=[]
#append() function to push elements into the stack
list.append('grapes')
print("push:",list)
list.append('blueberry')
print("push:",list)
list.append('strawberry')
print("push:",list)
#pop() function to remove the element from stack in LIFO order
list.pop()
print("pop:",list)
#peek to get the topmost element of the stack
print("peek:",list[-1])
list.pop()
print("pop:",list)
print("peek:",list[-1])

#(b) To implement queue using list.

# Initializing a queue
queue = []
# Adding elements to the queue
queue.append('red')
queue.append('blue')
queue.append('green')
print(queue)
# Removing elements from the queue
print(queue.pop(0))
print(queue.pop(0))
print(queue.pop(0))
print(queue)
