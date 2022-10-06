import java.util.Scanner;

class Node{
    int data;
    Node next;
    Node prev;
}

class DoubleLinkedList {
    Node head;

    boolean isEmpty(){
        if(head == null){
            return true;
        }
        else{
            return false;
        }
    }

    void insertFront(int data){
        Node newNode = new Node();
        newNode.data = data;
        newNode.prev = null;
        newNode.next = head;
        head.prev = newNode;
        head = newNode;
    }

    void insertRear(int data){
        Node newNode = new Node();
        newNode.data = data;
        newNode.next = null;
        newNode.prev = null;
        if(isEmpty()){
            head = newNode;
        }
        else{
            Node temp = head;
            while(temp.next != null){
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.prev = temp;
        }
    }

    void removeFront(){
        if(isEmpty()){
            System.out.println("Linked is empty");
        }
        else{
            if(head.next == null){
                head = null;
            }
            else{
                head = head.next;
            }
        }
    }

    void removeRear(){
        if(isEmpty()){
            System.out.println("Linked is empty");
        }
        else{
            if(head.next == null){
                head = null;
            }
            else{
                Node temp = head;
                Node prev = null;
                while(temp.next != null){
                    prev = temp;
                    temp = temp.next;
                }
                prev.next = null;
            }
        }
    }

    void viewFromFrontToRear(){

    }

    void viewFromRearToFront(){

    }

    void display(){

    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        DoubleLinkedList dll = new DoubleLinkedList();
        boolean goO = false;

        while(goO != true){
            System.out.println("Choose your option :");
            System.out.println("[1] insert Front");
            System.out.println("[2] insert Rear");
            System.out.println("[3] remove Front");
            System.out.println("[4] remove Rear");
            System.out.println("[5] view from end");
            System.out.println("[6] view from head");
            System.out.println("[7] display");
            System.out.println("[8] exit");
            System.out.print("Enter Choice :");
            int op = scan.nextInt();
            switch (op) {
                case 1:
                    System.out.print("Enter Data : ");
                    int dataIn = scan.nextInt();
                    dll.insertFront(dataIn);
                    break;
                case 2:
                    System.out.print("Enter Data : ");
                    int dataIn1 = scan.nextInt();
                    dll.insertRear(dataIn1);
                    break;
                case 3:
                    break;
                default:
                    System.out.println("Invalid Input");
                    break;
            }
        }
    }
}
