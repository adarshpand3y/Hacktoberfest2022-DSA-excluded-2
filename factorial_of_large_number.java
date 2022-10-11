import java.io.*;
import java.util.*;
class Node{
    int data;
    Node next;
   Node(int val)
   {
       data=val;
       next=null;
   }
}
class Pr{
    public static void multiplication(Node tail,int n) {
        int data=0,carry=0;
        Node temp=tail,prevnode=tail;
        while(temp!=null) {
            data=temp.data*n+carry;
            temp.data=data%10;
            carry=data/10;
            prevnode=temp;
            temp=temp.next;
        }
        while(carry!=0) {
             prevnode.next=new Node(carry%10);
             carry=carry/10;
             prevnode=prevnode.next;
        }
    }
    public static void print(Node tail) {
        if(tail==null)
            return;
        print(tail.next);
        System.out.print(tail.data);
    }
    public static void main(String args[]) {
    Node tail=new Node(1);
    Scanner ob=new Scanner(System.in);
    int input=ob.nextInt();
    for(int i=2;i<=input;i++)
    multiplication(tail,i);
    print(tail);
    
    }
}
