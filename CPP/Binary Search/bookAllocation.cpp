//author : Priyansh67
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> arr, int n, int m, int mid) {
        int pageSum = 0, studentCount = 1;
        for(int i=0; i<n; i++) {
            if(pageSum + arr[i] <= mid) {
                pageSum += arr[i];
            }
            else {
                studentCount++;
                if(studentCount > m || arr[i] > mid){
                    return false;
                }
                pageSum = arr[i];
            }
        }
        return true;    
    }

    int allocateBooks(vector<int> arr, int n, int m) {
        int s=0,sum=0;
        for(int x:arr) sum+=x;
        int e=sum,ans=-1;
        while(s <= e) {
            int mid = s+(e-s)/2;
            if(isPossible(arr,n,m,mid)) {
                ans = mid;
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;

        vector<int> v(n);
        for(int i=0;i<n;i++) 
            cin>>v[i];        

        Solution s;
        cout<<s.allocateBooks(v,n,m)<<endl;
    }
    return 0;
}