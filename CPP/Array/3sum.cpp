#include<bits/stdc++.h>
using namespace std;

 vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    vector<int>temp;
                    
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                 else if(nums[i]+nums[j]+nums[k]>0)
                 {
                     k--;
                 }
                else
                    j++;
            }
        }
        
        vector<vector<int>>finalans;
        for(auto i:ans)
            finalans.push_back(i);
        return finalans;
    }
int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(auto &i:arr)
    cin>>i;
  vector<vector<int>>res=threeSum(arr);
  for(int i=0;i<res.size();i++)
    cout<<res[i][0]<<" " <<res[i][1]<<" " <<res[i][2]<<endl;
  return 0;
}
  
