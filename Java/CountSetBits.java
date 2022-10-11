// Java program for the above approach
import java.util.*;
class GFG{

// Function that counts the set bits
// from 0 to N
static int countSetBit(int n)
{
	int i = 0;

	// To store sum of set bits from 0 - N
	int ans = 0;

	// Until n >= to 2^i
	while ((1 << i) <= n)
	{

		// This k will get flipped after
		// 2^i iterations
		boolean k = true;

		// Change is iterator from 2^i to 1
		int change = 1 << i;

		// This will loop from 0 to n for
		// every bit position
		for (int j = 0; j <= n; j++)
		{
			ans += k==true?0:1;

			if (change == 1)
			{

				// When change = 1 flip the bit
				k = !k;

				// Again set change to 2^i
				change = 1 << i;
			}
			else
			{
				change--;
			}
		}

		// Increment the position
		i++;
	}

	return ans;
}

// Function that counts the set bit
// in the range (L, R)
static int countSetBits(int L, int R)
{

	// Return the count
	return Math.abs(countSetBit(R) -
					countSetBit(L - 1));
}

// Driver Code
public static void main(String[] args)
{
	// Given L and R
	int L = 3, R = 5;

	// Function Call
	System.out.print("Total set bit count is " +
					countSetBits(L, R) +"\n");
}
}

// This code is contributed by gauravrajput1
