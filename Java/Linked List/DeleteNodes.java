public class DeleteNodes {
    static class Node{
        Node next; int data;
        Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    static Node head;
    void deleteFist(){          //delete the first node i.e, head node
        Node temp = head;
        if (head == null){
            return;
        }
        temp = temp.next;
        head = temp;
        temp = head;
    }

    void deleteLast(){          //delete the last node
        Node temp = head;
        while (temp.next != null){
             temp = temp.next;
         }
        temp.next = null;
    }

    // rest of the code for displaying the nodes is same as that of class - AddingNodes.java
}
