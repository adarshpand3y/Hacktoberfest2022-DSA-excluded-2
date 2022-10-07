public class reverse_linkedlist {
 
    // Create a class Node to enter values and address in the list
    static class node {
        int val;
        node next;
    };
 
    static node head = null;
    static int count(node head)
    {
        node p = head;
        int k = 1;
        while (p != null) {
            p = p.next;
            k++;
        }
        return k;
    }
 
    static node ll_reverse(node head)
    {
        node p = head;
        int i = count(head), j = 1;
        int[] arr = new int[i];
        while (i != 0 && p != null) {
            arr[j++] = p.val;
            p = p.next;
            i--;
        }
        j--;
        while (j != 0) 
            System.out.print(arr[j--] + " ");
        return head;
    }
    static node insert_end(node head, int data)
    {
        node q = head;
        node p = new node();
        p.val = data;
        p.next = null;
        while (q.next != null)
            q = q.next;
        q.next = p;
        p.next = null;
        return head;
    }
 

    static node create_ll(node head, int data)
    {
        node p = new node();
        p.next = null;
        p.val = data;
        if (head == null) {
            head = p;
            p.next = null;
            return head;
        }
        else {
            head = insert_end(head, data);
            return head;
        }
    }
 
    public static void main(String[] args)
    {
        int i = 5, j = 1;
        while (i != 0) {
            head = create_ll(head, j++);
            i--;
        }
        head = ll_reverse(head);
    }
}
