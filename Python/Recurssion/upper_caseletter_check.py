
#  function of finding uppercase letter in a string
def find_uppercase(input_str, index=0):
    if input_str[index].isupper():
        return input_str[index]
    if index == len(input_str)-1:
        return "No Uppercase Letters"
    return find_uppercase(input_str, index+1)


# driver code
input_str = input()
print(find_uppercase(input_str))
