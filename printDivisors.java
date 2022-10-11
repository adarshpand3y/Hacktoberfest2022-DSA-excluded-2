// Java implementation of Naive method to print all
// divisors

class Test
{
	// method to print the divisors
	static void printDivisors(int n)
	{
		for (int i=1;i<=n;i++)
			if (n%i==0)
				System.out.print(i+" ");
	}

	// Driver method
	public static void main(String args[])
	{
		System.out.println("The divisors of 100 are: ");
		printDivisors(100);;
	}
}
