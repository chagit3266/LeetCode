public class Solution {
    public int CountNegatives(int[][] grid) {
        int count_neg = 0;
        int n = grid.Length;
        int m = grid[0].Length;
        if(grid[n-1][m-1] >= 0)
           return 0;
        if(grid[0][0] < 0)
           return m*n;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(grid[i][j] < 0){
                    count_neg++;
                }
            }
        }
        return count_neg;
    }
}