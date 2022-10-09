#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int A[n];
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		int ptr1=0,ptr2=n-1;
		vector<int> B;

		//2 pointers
		while(B.size()<n){
			if(A[ptr1]<=A[ptr2]){
				B.push_back(A[ptr1]);
				ptr1++;
			}
			else{
				B.push_back(A[ptr2]);
				ptr2--;
			}
		}

		string ans="YES";


		for(int i=0;i<n-1;i++){
			if(B[i+1]<B[i]){
				ans="NO";
				break;
			}
		}
		cout<<ans<<'\n';
	}
}
