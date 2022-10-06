
#  function of count consonants in a string
def count_consonent(input_str):
    if input_str == "":
        return 0
    if input_str[0].lower() not in vowels and input_str[0].isalpha():
        return 1 + count_consonent(input_str[1:])
    else:
        return count_consonent(input_str[1:])


# driver code
input_str = input()
vowels = "aeiou"
print(count_consonent(input_str))
