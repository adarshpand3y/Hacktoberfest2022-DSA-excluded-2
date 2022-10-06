/*
 ---- STACK ----
 1. isEmpty
 2. isFull
 3. push
 4. pop
 5. display
 */

import java.util.Scanner;

class MyStack{

    int arr[];
    int size, top;
    
    MyStack(int size){
        this.size = size;
        arr = new int[size];
        top = -1;
    }

    boolean isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    boolean isFull(){
        if(top == size-1){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int data){
        if(isFull()){
            System.out.println("Stack Overflow");
        }
        else{
            arr[++top] = data;
        }
    }

    void pop(){
        if(isEmpty()){
            System.out.println("Stack Underflow");
        }
        else{
            int popV = arr[top--];
            System.out.println(popV);
        }
    }

    void peek(){
        if(isEmpty()){
            System.out.println("Stack Underflow");
        }
        else{
            System.out.println(arr[top]);
        }
    }

    void display(){
        if(isEmpty()){
            System.out.println("Stack is Empty");
        }
        else{
            for(int i = 0; i<=top; i++){
                System.out.print("["+arr[i]+"]");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        MyStack stack = new MyStack(5);
        boolean goO = false;

        while(true){
            System.out.println(" What You want :");
            System.out.println("[1] push");
            System.out.println("[2] pop");
            System.out.println("[3] peek");
            System.out.println("[4] display");
            System.out.println("[5] Exit");
            System.out.print("Enter your Option : ");
            int op = scan.nextInt();
            switch (op) {
                case 1:
                    System.out.print("Enter Data : ");
                    int dataIn = scan.nextInt();
                    stack.push(dataIn);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.peek();
                    break;
                case 4:
                    stack.display();
                    break;
                case 5:
                    goO = true;
                default:
                    System.out.println("Invalid Input");
                    break;
            }
            if(goO){
                break;
            }
        }
    }
}
