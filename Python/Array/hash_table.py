# Python program for HashTable 

hash_Table = [[],] * 10

def check_Prime(n):
    if n == 1 or n == 0:
        return 0
    for i in range(2, n//2):
        if n % i == 0:
            return 0
    return 1
def get_Prime(n):
    if n % 2 == 0:
        n = n + 1

    while not check_Prime(n):
        n += 2
    return n

def hash_Function(key):
    capacity = get_Prime(10)
    return key % capacity

def insert_Data(key, data):
    index = hash_Function(key)
    hash_Table[index] = [key, data]

def remove_Data(key):
    index = hash_Function(key)
    hash_Table[index] = 0

insert_Data(2000, "pineapple")
insert_Data(2500, "orange")
insert_Data(3000, "strawberry")
insert_Data(3500, "blueberry")
print(hash_Table)

remove_Data(3000)
print(hash_Table)