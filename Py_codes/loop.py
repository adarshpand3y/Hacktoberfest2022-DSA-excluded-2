# Python program for
# iterating over array
import numpy as geek

# creating an array using
# arrange method
a = geek.arange(9)

# shape array with 3 rows
# and 4 columns
a = a.reshape(3, 3)

# iterating an array
for x in geek.nditer(a):
	print(x)
