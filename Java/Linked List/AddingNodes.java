public class AddingNodes {
    static class Node{
        Node next; int data;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    static Node head;

     void addFirst(int data){             // add node at the begening of the list
        Node temp = new Node(data);
        if (head == null){
            head = temp;
            temp = head;
        }

        temp.next = head;
        head = temp;
         temp = head;
    }

     void addMiddle(int data, Node previous){             //add node between any given nodes
        Node tmep = new Node(data);
        if (head.next == null)
            return;

        previous.next.next = tmep.next;
        previous.next = tmep;
    }

     void addLast(int data){                    //add node at the last of the list
        Node temp = head;
        Node new_Node = new Node(data);
        while (temp.next != null){
            temp = temp.next;
        }
        temp.next = new_Node;
    }

     int sizeOfList(){                //return the size of the list
        int count = 0;
        Node temp = head;
        while (temp != null)
        {
            count++;
            temp = temp.next;
        }
        return count;
    }

    void displayList(){
         Node temp = head;
         while (temp != null){
             System.out.print(temp.data + "->");
             temp = temp.next;
         }
    }

    public static void main(String[] args) {
        AddingNodes list = new AddingNodes();
        list.head = new Node(2);
        Node two = new Node(3);
        Node three = new Node(4);
        head.next = two;
        two.next = three;

        list.addFirst(5);
        list.addMiddle(6, three);
        list.addLast(5);
        int size = list.sizeOfList();
        list.displayList();
        System.out.println("size of list: " + size);

    }
}
