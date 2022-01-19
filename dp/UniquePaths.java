class UniquePaths {
    
    
    
    
    public int allPathsOptimalSpace(int m, int n){
        //T.C: O(m*n)
        //S.C: O(n)
        int[][] dp = new int[m][n];
        
        //base cases (this time explicitly handled)
        for(int i=0; i<m; i++){
            dp[i][0] = 1;
        }
            for(int j=0; j<n; j++){
            dp[0][j] = 1;
        }
        
            
        
        int[] prevRow = dp[0];
        for(int i=1; i<m; i++){
            int[] currRow = dp[i];   //this currRow contains the first element as 1 and rest as 0 as of now
            for(int j=1; j<n; j++){
                    int up = prevRow[j]; //dp[i-1][j];
                   int  left = currRow[j-1]; //dp[i][j-1];
                     currRow[j] = up+left;  //general case
                }
            prevRow = currRow;    //currRow successfully calculate now it becomes prevRow for next (i+1)th row
            }
        
        
        return prevRow[n-1]; //dp[m-1][n-1];
        
    }
    
    
    
    

    
    public int allPathsTabulation(int m , int n){
        //T.C: O(m*n)
        //S.C: O(m*n)
        int[][] dp = new int[m][n];
        
        //base cases
        //first row and first col cells should be 1 
        //(we will handle this case in main for loop itself )
        
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0) dp[i][j] = 1;
                else{
                    int up = dp[i-1][j];
                   int  left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }
        
        return dp[m-1][n-1];
    
    }
    
    public int allPathsMemoization(int m, int n , int r, int c, int[][] dp){
        //from (m-1, n-1) --> (0, 0)
        //T.C: O(m*n)  (maximum m*n calls possible)
        //S.C: O(recursive stack) + O(dp[][]) = O(m-1 + n-1) + O(m*n)
        
        
        if(r==0 && c==0){
            return 1; //reach the dest, one valid path found
        }
        
        if(r<0 || c<0){
            return 0; //invalid path
        }
        
        //check if already calculated
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        
        //otherwise calculate
        int up = allPathsRecur(m, n, r-1, c);
        int left = allPathsRecur(m, n, r, c-1);
        
        
        return  dp[r][c] =up+left;   //save and return   
        
    }
    
    
    
    public int allPathsRecur(int m, int n, int r, int c){
        //from (m-1, n-1) --> (0, 0)
        //T.C: O(2^mn )
        //S.C: O(length of path) = O(m-1 + n-1)
        
        
        if(r==0 && c==0){
            return 1; //reach the dest, one valid path found
        }
        
        if(r<0 || c<0){
            return 0; //invalid path
        }
        
        int up = allPathsRecur(m, n, r-1, c);
        int left = allPathsRecur(m, n, r, c-1);
        
        return up+left;
    }
    public int uniquePaths(int m, int n) {
        
        // return allPathsRecur(m, n, m-1, n-1);
        
        int[][] dp = new int[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = -1;
            }
        }
            // return allPathsMemoization( m, n , m-1, n-1, dp);
        // return allPathsTabulation(m, n);
         return allPathsOptimalSpace(m, n);
        

}
}
