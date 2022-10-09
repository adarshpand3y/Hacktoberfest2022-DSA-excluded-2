
#include <bits/stdc++.h>
using namespace std;
    //Function is to check whether two strings are anagram of each other or not.

//anagram means a word, phrase, or name formed by rearranging the letters of another, such as spar, formed from rasp
    bool isAnagram(string a, string b){
    
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n;
        if(a==b){
            return 1;
        }
        if(a.length()>b.length()){
        n=a.length();
        }
        else{
            n=b.length();
        }
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                return 0;
            }
        }
        return 1;
    }

int main() {

    string s1 = "secure", s2 = "rescue" ;
    
    cout<<isAnagram(s1,s2)<<endl;
       
    string a = "allergy", b = "allergic";

    cout<<isAnagram(a,b)<<endl;
}