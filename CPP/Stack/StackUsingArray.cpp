
#include<iostream>
using namespace std;

class stackusingarray{

    int *data;
    int nextindex;
    int capacity=4;
public:
    stackusingarray(){
        data=new int[capacity];
        nextindex=0;


    }
    int size(){
        return nextindex;
    }

    bool isempty(){
        // if(nextindex==0)
        //     return true;
        // else
        //     return false;

        // short form
        return nextindex==0;
        // in above it behaves as boolean as 0==0 then give true otherwise false 
    }



    void push(int element){
        if(nextindex==capacity){
            int *newdata=new int[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i]=data[i];
            }
            
            capacity *=2;
            delete []data;
            data=newdata;
        }
        data[nextindex]=element;
        nextindex++;
    }

    int pop(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return -1;

        }
        nextindex--;
        return data[nextindex];
    }
    int peek(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return -1;

        }
        return data[nextindex-1];
    }

    void display(){
        for (int i = 0; i < nextindex; i++)
        {
            cout<<data[i]<<" ";
        }
        
    }


};

int main(){


    stackusingarray s1;
    stackusingarray s2;
   
    s1.push(800);
    s1.push(900);
    s1.push(1100);
    s1.push(220);
    
    cout<<s2.isempty()<<endl;

    
    cout<<s1.pop()<<endl;


    cout<<s1.peek()<<endl;

    cout<<s1.size()<<endl;
    s1.display();


    
    return 0;
}
