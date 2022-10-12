#include <bits/stdc++.h>
using namespace std;

// Function to check whether the string is palindrome
string isPalindrome(string S)
{
	string P = S;
	reverse(P.begin(), P.end());

   if (S == P) {	return "Yes";	}
	else { return "No"; }
}

int main()
{  
   string S;
	cin>>S;
   
   cout << isPalindrome(S);

	return 0;
}
