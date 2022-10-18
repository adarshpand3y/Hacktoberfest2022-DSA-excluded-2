import java.util.*;

public class ContainerWithMostWater {
    public static int mostWater(int[] heights) {
        int i = 0, j = heights.length - 1;
        int maxWater = 0;
        while(i < j){
            int h = Math.min(heights[i], heights[j]);
            int w = j - i;
            maxWater = Math.max(maxWater, h * w);
            if(heights[i] < heights[j])i++;
            else j--;
        }
        return maxWater;
    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] heights = new int[n];
        for(int i = 0; i < n; i++) {
            heights[i] = scn.nextInt();
        }

        int res = mostWater(heights);
        System.out.println(res);
        scn.close();
    }
}