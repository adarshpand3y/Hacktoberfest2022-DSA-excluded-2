#include <iostream>
using namespace std;

string revString(string s, int len)
{
    string res = "";
    for (int i = len - 1; i >= 0; i--)
    {
        res += s[i];
    }
    return res;
}

int main()
{
    string text = "Hello Coders! Have a great day";

    int len = text.length();
    cout << revString(text, len) << endl;

    /*
    USING REVERSE FUNCTION
    reverse(text.begin(), text.end());
    cout << text << endl;
    */

    return 0;
}