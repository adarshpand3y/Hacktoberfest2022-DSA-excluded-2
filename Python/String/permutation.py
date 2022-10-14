# Finding permutations using itertools rather than the conventional method

# Ther permutations has been generated without any restrictions on the word "qwerty".

# Import permutations
from itertools import permutations
string1 = "qwerty"
 
# Printing the declard string
print("Initial string", string1)
 
# Finding the permutations
permutation = [''.join(i) for i in permutations(string1)]

# result
print("Resultant List", str(permutation))

# Total 720 different permutations would be generated
