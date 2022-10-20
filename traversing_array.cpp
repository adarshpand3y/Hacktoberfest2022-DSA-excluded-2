#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vector={10,20,30,40,50};
    cout<<vector.size()<<endl;  //vector size

    //traversing
    for(int i=0; i<vector.size(); i++){
        cout<<vector[i]<<" ";
    }
    cout<<endl;
    cout<<"size of vector before pop_back: "<<vector.size()<<endl;

    vector.push_back(100);
    vector.push_back(200);
    vector.push_back(1000);
    vector.push_back(2000);
    vector.push_back(3000);
     for(int i=0; i<vector.size(); i++){
        cout<<vector[i]<<" ";
    }
    cout<<endl;
    cout<<"size of vector after push_back: "<<vector.size()<<endl;
    return 0;

}
