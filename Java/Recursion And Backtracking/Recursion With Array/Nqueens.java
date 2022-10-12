public class Nqueens {       //O(n!)  T(n)=1queen *T(n-1)+issafe
                                         //{  1queen- //O(n)}

    public static boolean isSafe(char board[][],int row, int col){  
        //vertical
        for(int i=row-1;i>=0;i--){
        
        if (board[i][col]=='Q'){
            return false;
                }
         }
         //left up

         for (int i=row-1,j=col-1;i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q'){
            return false;
            }


         }//rigtht up
         for (int i=row-1,j=col+1;i>=0 && j<board.length;i-- ,j++){
            if(board[i][j]=='Q'){
            return false;
            }

         }
         return true;

    }

    public static void printqueens(char board[][],int row){
        if (row==board.length){
            printboard(board);
            return;
        }
        for (int j=0;j<board.length;j++){
            if (isSafe(board,row,j)){
            board[row][j]='Q';
            printqueens(board, row+1);//function call
                board[row][j]='x';//backtracking
            }
        }
    }
    public static void printboard(char board[][]){
        System.out.println("------------new board------------");
        for (int i=0;i<board.length;i++){
            for (int j=0;j<board.length;j++){
                System.out.print(board[i][j]);


            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        int n=4;
        char board[][]=new char[n][n];
        for (int i=0;i<board.length;i++){
            for (int j=0;j<board.length;j++){
                board[i][j]='x';

            }
        }
        printqueens(board,0);

    }
}
