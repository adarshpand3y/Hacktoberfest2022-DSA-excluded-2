import java.util.*;
public class MenuDriven {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Press 1 for enter marks: \n" + "Press 0 for exit !");
        int n = sc.nextInt();
        int a = 0;
        if (n == 1) {
            System.out.println("Marks obtained out of 100:");
            a = sc.nextInt();
        } else if (n == 0) {
            System.out.println("stopping the process...");
            return;
        } else {
            System.out.println("Invalid Input error..");
        }
        if (a>=90){
            System.out.println("This is good");
        } else if (a>=60 && a<=89){
            System.out.println("This is good too");
        }
        else {
            System.out.println("Effort Matters !");
        }
    }
    }

