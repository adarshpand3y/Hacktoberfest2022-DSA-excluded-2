#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
        
        int i=0,n=s.length(),ans=0;
        while(i<n)
        {
            if(s[i]=='C')
            {
                ans+=100;
                i++;
                if(i<n && s[i]=='M')
                {
                    ans-=100;
                    ans+=900;
                    i++;
                    continue;
                }
                else if (i<n && s[i]=='D')
                {
                    ans-=100;
                    ans+=400;
                    i++;
                    continue;
                }
            }
            if(s[i]=='X')
            {
                ans+=10;
                i++;
                if(i<n && s[i]=='C')
                {
                    ans-=10;
                    ans+=90;
                    i++;
                    continue;
                }
                else if(i<n && s[i]=='L')
                {
                    ans-=10;
                    ans+=40;
                    i++;
                    continue;
                }
            }
            if(s[i]=='I')
            {
                ans+=1;
                i++;
                if(i<n && s[i]=='X')
                {
                    ans-=1;
                    ans+=9;
                    i++;
                    continue;
                }
                else if(i<n && s[i]=='V')
                {
                    ans-=1;
                    ans+=4;
                    i++;
                    continue;
                }
            }
            if(s[i]=='M'){ans+=1000;i++;}
            if(s[i]=='D'){ans+=500;i++;}
            if(s[i]=='L'){ans+=50;i++;}
            if(s[i]=='V'){ans+=5;i++;}
            
        }
        return ans;
    }

int main()
{
    string roman_str="MMXXII";
    cout<<romanToInt(roman_str)<<endl;
    return 0;
}