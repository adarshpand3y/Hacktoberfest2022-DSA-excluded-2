
#include<bits/stdc++.h>
using namespace std;

int no_of_rots(vector<int> g1)
{
    int start = 0;
    int end = g1.size() -1;
    int N = g1.size();
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        int next = (mid+1)%N;
        int prev = (mid+N-1)%N;

        if(g1.at(mid)<=g1.at(next) && g1.at(mid)<=g1.at(prev))
        {
            return mid;
        }
        else if(g1.at(mid)<=g1.at(end))
            end = mid-1;
        else{start = mid+1;}
    }
    return -1;
}
int bs(vector<int> g1, int start, int end,int element)
{
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(element == g1.at(mid))
        {
            return mid;
        }
        else if(element <= g1.at(mid))
            end = mid-1;
        else{start = mid+1;}
    }
    return -1;
}



int main()
{
    int n;
    cin>>n;
    vector<int> g1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        g1.push_back(x);
    }
    int element;
    cin>>element;
    int n1 = no_of_rots(g1);
    int s1 = 0;
    int e1 = n1-1;
    int s2 = n1;
    int e2 = g1.size()-1;
    int ans1 = bs(g1,s1,e1,element);
    int ans2 = bs(g1,s2,e2,element);
    if(ans1 == -1 && ans2 == -1)
        cout<<-1;
    else if(ans1 == -1)
        cout<<ans2;
    else
        cout<<ans1;
}

