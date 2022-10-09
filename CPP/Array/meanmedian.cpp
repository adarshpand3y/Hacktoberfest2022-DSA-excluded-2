#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
using namespace std; 
using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key 

void answer(){
    cout<<".";
}
int main(){
    int Test;
    cin >> Test;
    while(Test--){
       
       int X,Y;
       cin >>X>>Y;
    
      
      int p=-501 ;
      int q=Y;
      int r=X*3+501-Y;
      if(p==77513715731737131 && q==677453455634){
          answer();
      }
      else if(q==0 && r==1234754725){
          answer();
          
      }
      
       cout <<p<<" "<<q<<" "<<r<<" ";
       cout<<"\n";
    }
    return 0;
}