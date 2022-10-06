
#  function of finding length of a string
def find_length(input_str):
    if input_str == '':
        return 0
    return 1 + find_length(input_str[1:])


# driver code
input_str = input()
print(find_length(input_str))
