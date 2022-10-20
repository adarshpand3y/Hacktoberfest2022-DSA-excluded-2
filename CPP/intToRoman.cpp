#include <iostream.h>
#include <vector>

class Solution {
public:
   vector<int> numbers = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
vector<string> num_str = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

string intToRoman(int num)
{
    string answer = "";

    while (num > 0)
    {
        int index = upper_bound(numbers.begin(), numbers.end(), num) - numbers.begin() - 1;
        answer += num_str[index];
        num -= numbers[index];
    }

    return answer;
}
};

int main()
{
  solution t;
  t.intToRoman(10);
  
}
  
