
'''Welcome to guess game
   Here you have to guess
   a 4 digit number and you
   will be given 10 chances
          Good Luck'''

import random
def computer_choice():
    choice1 = str(random_num)
    choice2 = map(int, choice1)  # function to convert the random no generated to list
    choice_list = list(choice2)
    return choice_list

def userinput():
    input1 = int(input("Enter Your Guess"))
    input2 = str(input1)
    input3 = map(int, input2)
    input_list = list(input3)
    return input_list

random_num = random .randint(1000, 9999)  # 4 digit code generated

a = computer_choice()
i = 0
while (i < 10):
    result = ""
    b = userinput()

    if len(b) != 4:
        print("As it is already asked to enter only 4 digit number")
        continue
    if (b == a):
        print("You guessed right !", a)
        break
    for elements in b:
        if elements in a:
            if b.index(elements) == a.index(elements):
                result += "R"
            else:
                result += "A"
        else:
            result += "W"
    print(result)
    i += 1

else:
    print("You are out of choices", a)

