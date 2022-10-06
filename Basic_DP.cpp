//Some Basic Questions on DP :-

// DP to solve fibonacci series -
// Memoization - Top Down Approach
/*#include<bits/stdc++.h>
using namespace std;
int fibo(int n,int dp[]){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}
int main(){
    int dp[11];
    memset(dp,-1,sizeof(dp));
    cout<<fibo(10,dp);
    return 0;
}*/

// DP to solve fibonacci series -
// Tabulation - Bottom Up Approach
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int dp[11];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=10;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[10];
    return 0;
}*/

// DP to solve fibonacci series -
// Normal Approach
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int sum1=0,sum2=1;
    for(int i=2;i<=10;i++){
        int temp = sum1+sum2;
        sum1 = sum2;
        sum2 = temp;
    }
    cout<<sum2;
    return 0;
}*/

// DP to solve staircase problem -
// Memoization - Top Down Approach
/*#include<bits/stdc++.h>
using namespace std;
int staircase(int n,int dp[]){
    if(n<=2){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = staircase(n-1,dp)+staircase(n-2,dp);
    return dp[n];
}
int main(){
    int dp[11];
    memset(dp,-1,sizeof(dp));
    cout<<staircase(10,dp);
    return 0;
}*/


// DP to solve staircase problem -
// Tabulation - Bottom Up Approach
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int dp[11];
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=10;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[10];
    return 0;
}*/


// DP to solve staircase problem -
// Normal Approach
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int prev2=1;
    int prev=2;
    for(int i=3;i<=10;i++){
        int temp = prev2+prev;
        prev2 = prev;
        prev= temp;
    }
    cout<<prev;
    return 0;
}*/


// DP to solve frog jump problem -
// Memoization - Top Down Approach
/*#include<bits/stdc++.h>
using namespace std;
int jump(vector<int> &a,int n,vector<int> &dp){
    if(n==0){
        return 0;   
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int left = jump(a,n-1,dp)+abs(a[n]-a[n-1]);
    int right = INT_MAX;
    if(n>1){
        right = jump(a,n-2,dp)+abs(a[n]-a[n-2]);
    }
    return dp[n] = min(left,right);
}
int main(){
    vector<int> arr{30,20,60,40,60,60};
    //vector<int> arr{10,20,30,10};
    int n=arr.size();
    vector<int> dp(n+1,-1);
    cout<<jump(arr,n-1,dp);
    return 0;
}*/

// DP to solve frog jump problem -
// Tabulation - Bottom up Approach
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr{30,20,60,40,60,60};
    //vector<int> arr{10,20,30,10};
    int n=arr.size();
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int left = dp[i-1]+abs(arr[i]-arr[i-1]);
        int right = INT_MAX;
        if(n>1){
            right = dp[i-2]+abs(arr[i]-arr[i-2]);
        }
        dp[i]=min(left,right);
    }
    cout<<dp[n-1];
    return 0;
}*/

// DP to solve frog jump problem -
// Normal Approach
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr{30,20,60,40,60,60};
    //vector<int> arr{10,20,30,10};
    int n=arr.size();
    int first=0;
    int second=0;
    for(int i=1;i<n;i++){
        int left = first+abs(arr[i]-arr[i-1]);
        int right = INT_MAX;
        if(n>1){
            right = second+abs(arr[i]-arr[i-2]);
        }
        int temp = min(left,right);
        second = first;
        first = temp;
    }
    cout<<first;
    return 0;
}*/

// DP to solve frog jump problem with k jumps -
// Memoization - Top Down Approach
/*#include<bits/stdc++.h>
using namespace std;
int jump(vector<int> &arr,int n,int k){
    if(n==0){
        return 0;   
    }
    int temp = INT_MAX;
    for(int j=1;j<=k;j++){
        if(n>=j){
            int ans=jump(arr,n-j,k)+abs(arr[n]-arr[n-j]);
            temp=min(temp,ans);
        }
    }
    return temp;
}
int main(){
    vector<int> arr{30,20,60,40,60,60};
    int n=arr.size()-1;
    cout<<jump(arr,n,4);
    return 0;
}*/

// DP to solve frog jump problem with k jumps -
// Tabulation - Bottom-Up Approach
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr{30,20,60,40,60,60};
    int n=arr.size(),k=4;
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int temp = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i>=j){
                int ans=dp[i-j]+abs(arr[i]-arr[i-j]);
                temp=min(temp,ans);
            }
        }
        dp[i]=temp;
    }
    cout<<dp[n-1];
    return 0;
}*/

// DP to find maximum sum of adjacent elements -
// Memoization - Top-Down Approach
/*#include<bits/stdc++.h>
using namespace std;
int f(vector<int> &arr,int n,vector<int> &dp){
    if(n==0){
        return arr[n];
    }
    if(n<0){
        return 0;
    }
    int pick = arr[n]+f(arr,n-2,dp);
    int notpick = f(arr,n-1,dp);
    return dp[n] = max(pick,notpick);
}
int main(){
    vector<int> arr{2,1,4,9};
    vector<int> dp(4);
    cout<<f(arr,3,dp);
    return 0;
}*/

// DP to find maximum sum of adjacent elements -
// Tabulation - Bottom-Up Approach
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr{2,1,5,6,7,3,4};
    vector<int> dp(7);
    dp[0]=arr[0];
    for(int i=1;i<7;i++){
        int pick = arr[i];
        if(i>1){
            pick = arr[i]+dp[i-2];
        }
        int notpick = dp[i-1];
        dp[i] = max(pick,notpick);
    }
    cout<<dp[6];
    return 0;
}*/

// DP to find maximum sum of adjacent elements -
// Normal Approach
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr{2,1,5,6,7,3,4};
    int prev2 = 0;
    int prev = arr[0];
    for(int i=1;i<7;i++){
        int pick = arr[i];
        if(i>1){
            pick = arr[i]+prev2;
        }
        int notpick = prev;
        int temp = max(pick,notpick);
        prev2 = prev;
        prev = temp;
    }
    cout<<prev;
    return 0;
}*/

// DP to find the maximum money Robber can rob from adjacent houses when all of the houses are located in a circle -
// Memoization - Top-Down Approach
/*#include<bits/stdc++.h>
using namespace std;
int f1(vector<int> &arr,int n,vector<int> &dp){
    if(n<=0){
        return 0;
    }
    int pick = arr[n]+f1(arr,n-2,dp);
    int notpick = f1(arr,n-1,dp);
    return dp[n] = max(pick,notpick);
}
int f2(vector<int> &arr,int n,vector<int> &dp){
    if(n==0){
        return arr[n];
    }
    if(n<0){
        return 0;
    }
    int pick = arr[n]+f2(arr,n-2,dp);
    int notpick = f2(arr,n-1,dp);
    return dp[n] = max(pick,notpick);
}
int main(){
    vector<int> arr{1,3,2,1};
    vector<int> dp(4);
    cout<<max(f1(arr,3,dp),f2(arr,2,dp));
    return 0;
}*/

// DP to find the maximum money Robber can rob from adjacent houses when all of the houses are located in a circle -
// Tabulation - Bottom-Up Approach
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr{2,1,5,6,7,3,4};
    vector<int> dp1(7);
    vector<int> dp2(7);
    dp1[0]=0;
    for(int i=1;i<7;i++){
        int pick = arr[i];
        if(i>1){
            pick = arr[i]+dp1[i-2];
        }
        int notpick = dp1[i-1];
        dp1[i] = max(pick,notpick);
    }
    dp2[0]=arr[0];
    for(int i=1;i<6;i++){
        int pick = arr[i];
        if(i>1){
            pick = arr[i]+dp2[i-2];
        }
        int notpick = dp2[i-1];
        dp2[i] = max(pick,notpick);
    }
    cout<<max(dp1[6],dp2[5]);
    return 0;
}*/