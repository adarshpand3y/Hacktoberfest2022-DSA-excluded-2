#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;
class Solution
{
public:
	int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}
};

int main()
{
	Solution inst;
	vector<pr> vt{{10, 20}, {4, 5}, {10, 0}, {10, 100}, {1, 11}};
	vector<int> res;
	for (auto it : vt)
	{
		res.push_back(inst.gcd(it.first, it.second));
	}

	for (int i = 0; i < vt.size(); i++)
	{
		cout << "GCD Of " << vt[i].first << "," << vt[i].second << " is -> " << res[i] << endl;
	}

	return 0;
}