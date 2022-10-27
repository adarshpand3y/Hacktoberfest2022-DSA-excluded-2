
#include <bits/stdc++.h>

using namespace std;


  int trap(vector<int>& arr) {
        int n = arr.size();
        
        int prev_max[n];
        int prev_m =0;
        
        int next_max[n];
        int next_m =0;
        
        for(int i =0 ;i<n ;i++)
        {
            prev_max[i] = prev_m;
            prev_m = max( prev_m,arr[i]);
        }
        
        for(int i =n-1 ;i>=0 ;i--)
        {
            next_max[i] = next_m;
            next_m = max( next_m ,arr[i]);
        }
        
        int ans =0;
        
        for(int i =0 ;i<n ;i++)
        {
             int z =(min(prev_max[i] , next_max[i]) - arr[i]);
            ans+= z>0? z:0;
        }
        return ans;
    }
int main() 
{
  vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout<<trap(heights)<<" units rainwater will be trapped";
  return 0;
}
