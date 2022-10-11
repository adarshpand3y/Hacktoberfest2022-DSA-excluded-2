public class pattern {
    static void Pattern(int N) {
//Enter your code here
        for (int i = 1; i <= N; i++) {
            if(i==1){
                System.out.println("*");
            }
            else if (i == N) {
                for (int j = 0; j < N; j++) {
                    System.out.print("*");
                }
            } else {
                for (int j = 1; j <= i+1; j++) {

                        if (j == 1 || j == i+1) {
                            System.out.print("*");
                        } else {
                            System.out.print("^");
                        }

                }
                System.out.println("");
            }
        }
    }

    public static void main(String[] args) {
        Pattern(3);
    }
}
