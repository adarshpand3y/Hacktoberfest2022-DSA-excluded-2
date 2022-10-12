public class sudoku {


    public static void sudokusolver(int arr[][],int row,int col){
        int ni=0,nj=0;
        if (row==arr.length){
            display(arr);
            return;
        }

        if (col==arr.length-1){
            ni=row+1;
            nj=0;

        }else{
            ni=row;
            nj=col+1;
        }
        if (arr[row][col]!=0){
            sudokusolver(arr, ni,nj);
        }else{
            for (int po=1;po<=9;po++){
                if(isvalid(arr,row,col,po)){
                    arr[row][col]=po;
                    sudokusolver(arr, ni, nj);
                    arr[row][col]=0;
                }
                
            }
        }

    }
    public static boolean isvalid(int arr[][],int x,int y,int val){
        //row
        for (int i=0;i<arr.length;i++ ){
        if (arr[i][y]==val){
            return false;
        }
        }
        //column
        for (int j=0;j<arr[0].length;j++){
            if (arr[x][j]==val){
                return false;
            }
        }
        //subarray
        int si=x/3*3;
        int sj=y/3*3;
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (arr[si+i][sj+j]==val){
                    return false;
                }
            }
        }
        return true;

    }
    public static void display(int arr[][]){
        for (int i=0;i<arr.length;i++){
            for (int j=0;j<arr[0].length;j++){
                System.out.print(arr[i][j]);
                
            }
            System.out.println();
        }
    }
    public static void main(String[] args){
        int sudoku[][]={{0,0,8,0,0,0,0,0,0},
                        {4,9,0,1,5,7,0,0,2},
                        {0,0,3,0,0,4,1,9,0},
                        {1,8,5,0,6,0,0,2,0},
                        {0,0,0,0,2,0,0,6,0},
                        {9,6,0,4,0,5,3,0,0},
                        {0,3,0,0,7,2,0,0,4},
                        {0,4,9,0,3,0,0,5,7},
                        {8,2,7,0,0,9,0,1,3}};
    
    sudokusolver(sudoku,0,0);

    }
}
