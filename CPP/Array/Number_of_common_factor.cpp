#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=12, b=6;
    int count = 0;
    for(int i = 1; i <= min(a, b); i++){
        if(a % i == 0 && b % i == 0) 
            count++;
    }
    cout<<"Number of common factors are: "<< count;
    return 0;
}