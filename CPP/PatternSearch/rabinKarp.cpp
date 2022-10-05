#include<bits/stdc++.h>

using namespace std;

const int t = 256;
const int w = 1283;

void Rabin_Karp_Algorithm(string text,string pattern){
    
    // Length of text and pattern
    int n = text.length();
    int m = pattern.length();
    
    int flag;
    int c=1,i=0;
    
    int hash_p=0,hash=0;
    while(i<m){
        hash_p=(hash_p*t + pattern[i])%w;
        hash=(hash*t + text[i])%w;
        i++;
    }
    
    for(int i=1;i<=m-1;i++)
        c=(c*t)%w;
    
    i=0;
    while(i<=n-m){
       if(hash_p==hash){
            flag=1;
            for(int j=0;j<m;j++){
                if(pattern[j]==text[i+j]){
                    continue;
                }
                else{
                    flag = 0;
                    break;
                }
           }
            if(flag==1){cout<<"Pattern found at index "<<i;return;}
       }
       
       
       //Calculate hash value of next window
       if(i<n-m){
           hash=((t*(hash-text[i]*c))+text[i+m])%w;
            if(hash<0){
                hash = hash + w;
            }
       }
       i++;
    }

    cout<<"Not found";
}

int main(){

    string txt,pat;
    cout<<"Enter text - ";
    cin>>txt;

    cout<<"Enter pattern - ";
    cin>>pat;

    Rabin_Karp_Algorithm(txt, pat);

}