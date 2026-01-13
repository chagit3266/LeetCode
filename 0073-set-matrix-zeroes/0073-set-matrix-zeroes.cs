public class Solution {
    public void SetZeroes(int[][] matrix) {

        if (matrix == null || matrix.Length == 0) return;

        bool firstRowZero = false;
        bool firstColZero = false;
        
        int m = matrix.Length;
        int n = matrix[0].Length;

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
         for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if( matrix[i][0] == 0 || matrix[0][j] == 0){          
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
}