#include<bits/stdc++.h>
using namespace std;
int main()
{int t,c;cin>>t;
while(t--){string s,s1;cin>>s;string v,v1;
for(int i=0;i<s.size();i++){
	if(int(s[i])%2==0)
	v+=s[i];
	else
	v1+=s[i];
}int j=0,k=0;
merge(v.begin(),v.end(),v1.begin(),v1.end(),s.begin());

	cout<<s<<endl;
}
}
