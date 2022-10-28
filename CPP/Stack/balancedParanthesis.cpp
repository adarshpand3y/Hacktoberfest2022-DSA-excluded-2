#include<iostream>
#include<stack>
using namespace std;
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        for(int i=0;i<x.size();i++){
            if(s.empty()){
                s.push(x[i]);
            }
            else if(x[i]=='}' && s.top()=='{' || x[i]==')' && s.top()=='(' || x[i]==']' && s.top()=='[' ){
                s.pop();
            }
            
          else{
                s.push(x[i]);
            }
            
        }
        
        if(s.empty()){
            return true;
        }
        return false;
    }

};

int main(){
  int t;
  string a;
  cin>>t;
  while(t--){
    cin>>a;
    Solution obj;
    if(obj.ispar(a))
       cout<<"balanced"<<endl;

    else
        cout<<"not balanced"<<endl;

    
  }

  return 0;


}