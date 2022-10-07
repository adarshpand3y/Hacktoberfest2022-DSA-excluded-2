//author : Priyansh67

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& num,int size) {
        
        int totalsum = 0;
        for(int x:num) totalsum += x;

        int leftsum = 0;

        for(int i=0; i<size; i++) {
            totalsum = totalsum - num[i];
            if(leftsum == totalsum)
                return i;
            else
                leftsum = leftsum + num[i];
        }
        return -1;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    Solution s;
    int ans = s.findMiddleIndex(v,n);

    cout<<"Pivot Element is at index : "<<ans<<endl;

}