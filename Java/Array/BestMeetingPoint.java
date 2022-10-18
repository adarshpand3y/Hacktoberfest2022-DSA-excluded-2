import java.util.*;

public class BestMeetingPoint {
    public static int minTotalDistance(int[][] grid) {
        // Write your code here
        ArrayList<Integer> xCoor = new ArrayList<>();
        for(int r = 0; r < grid.length; r++){
            for(int c = 0; c < grid[0].length; c++){
                if(grid[r][c] == 1)xCoor.add(r);
            }
        }
        ArrayList<Integer> yCoor = new ArrayList<>();
        for(int c = 0; c < grid[0].length; c++){
            for(int r = 0; r < grid.length; r++){
                if(grid[r][c] == 1)yCoor.add(c);
            }
        }
        int midX = xCoor.get(xCoor.size() / 2);
        int midY = yCoor.get(yCoor.size() / 2);
        int ans = 0;
        for(int x: xCoor)ans += Math.abs(x - midX);
        for(int y: yCoor)ans += Math.abs(y - midY);
        return ans;
    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();


        int[][] grid = new int[n][m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid[i][j] = scn.nextInt();
            }
        }

        int dist = minTotalDistance(grid);
        System.out.println(dist);
        scn.close();
    }
}