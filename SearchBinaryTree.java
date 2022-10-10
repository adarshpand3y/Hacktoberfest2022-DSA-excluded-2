public class SearchBinaryTree {  
  
      //Represent a node of binary tree  
      public static class Node{  
        int data;  
        Node left;  
        Node right;  
  
        public Node(int data){  
          //Assign data to the new node, set left and right children to null  
          this.data = data;  
          this.left = null;  
          this.right = null;  
        }  
      }  
  
      //Represent the root of binary tree  
      public Node root;  
  
      public static boolean flag = false;  
  
      public SearchBinaryTree(){  
        root = null;  
      }  
  
      //searchNode() will search for the particular node in the binary tree  
      public void searchNode(Node temp, int value){  
        //Check whether tree is empty  
        if(root == null){  
          System.out.println("Tree is empty");  
        }  
        else{  
          //If value is found in the given binary tree then, set the flag to true  
          if(temp.data == value){  
            flag = true;  
               return;  
          }  
          //Search in left subtree  
          if(flag == false && temp.left != null){  
             searchNode(temp.left, value);  
          }  
          //Search in right subtree  
          if(flag == false && temp.right != null){  
             searchNode(temp.right, value);  
          }  
        }  
      }  
  
      public static void main(String[] args) {  
  
        SearchBinaryTree bt = new SearchBinaryTree();  
        //Add nodes to the binary tree  
        bt.root = new Node(1);  
        bt.root.left = new Node(2);  
        bt.root.right = new Node(3);  
        bt.root.left.left = new Node(4);  
        bt.root.right.left = new Node(5);  
        bt.root.right.right = new Node(6);  
  
        //Search for node 5 in the binary tree  
           bt.searchNode(bt.root, 5);  
  
        if(flag)  
          System.out.println("Element is present in the binary tree");  
        else  
          System.out.println("Element is not present in the binary tree");  
      }  
    }