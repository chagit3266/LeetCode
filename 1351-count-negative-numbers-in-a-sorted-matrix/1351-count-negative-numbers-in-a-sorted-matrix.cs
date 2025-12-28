public class Solution {
    public int CountNegatives(int[][] grid) {
        int count_neg = 0;
        int n = grid.Length;
        int m = grid[0].Length;
        int i = n-1;
        int j = 0;
        if(grid[n-1][m-1] >= 0)
           return 0;
        if(grid[0][0] < 0)
           return m*n;
        while(i >= 0 && j < m){
            if(grid[i][j] < 0){
                count_neg += m - j;
                i--;
            }else{
                j++;
            }
        }
        return count_neg;
    }
}