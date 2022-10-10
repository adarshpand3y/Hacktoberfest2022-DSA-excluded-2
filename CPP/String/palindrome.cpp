#include <bits/stdc++.h>
using namespace std;

string isPalindrome(string s){
    string n=s;

    //reversing string n
    reverse(n.begin(), n.end());

    //condition to be palindrome
    if (s==n){
        return "is a palindrome";
    }
    else
        return "is not a palindrome";
}

int main(){
    string s="abdedcba";
    cout<<isPalindrome(s);
    return 0;
}