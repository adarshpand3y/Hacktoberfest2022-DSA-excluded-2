import java.util.Scanner;

class LinierQueue{
    int size, front, rear;
    int myArr[];

    LinierQueue(int size){
        this.size = size;
        myArr = new int[size];
        front = rear = -1;
    }

    boolean isFull(){
        if(rear == size-1){
            return true;
        }
        else{
            return false;
        }
    }

    boolean isEmpty(){
        if(rear == -1 && front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data){
        if(isFull()){
            System.out.println("Queue Overflow");
        }
        else{
            if(isEmpty()){
                front = 0;
            }
            rear++;
            myArr[rear] = data;
        }
    }

    void dequeue(){
        if(isEmpty()){
            System.out.println("Queue is empty");
        }
        else{
            if(rear == front){
                front = rear = -1;
            }
            else{
                front++;
            }
        }
    }

    void viewFront(){
        if(isEmpty()){
            System.out.println("Queue is empty");
        }
        else{
            System.out.println(myArr[front]);
        }
    }

    void viewRear(){
        if(isEmpty()){
            System.out.println("Queue is empty");
        }
        else{
            System.out.println(myArr[rear]);
        }
    }

    void display(){
        if(isEmpty()){
            System.out.println("Queue is empty");
        }
        else{
            for(int i = front; i<= rear; i++){
                System.out.println("["+myArr[i]+"]");
            }
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter Size of the Queue : ");
        int size = scan.nextInt();
        LinierQueue lq = new LinierQueue(size);
        boolean goO = false;

        while(goO != true){
            System.out.println("Select Options given below :");
            System.out.println("[1] enqueue");
            System.out.println("[2] dequeue");
            System.out.println("[3] view front");
            System.out.println("[4] view rear");
            System.out.println("[5] display");
            System.out.println("[6] exit");
            System.out.print("Enter option : ");
            int op = scan.nextInt();
            switch (op) {
                case 1:
                    System.out.print("Enter data :");
                    int dataIn = scan.nextInt();
                    lq.enqueue(dataIn);
                    break;
                case 2:
                    lq.dequeue();
                    break;
                case 3:
                    lq.viewFront();
                    break;
                case 4:
                    lq.viewRear();
                    break;
                case 5:
                    lq.display();
                    break;
                case 6:
                    goO = true;
                    break;
                default:
                    break;
            }
        }
    }
}
