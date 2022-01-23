//class Solution {
class MinPathSumGrid{

private int minPathOptimalSpace(int[][] grid){
/* T.C: O(m*n)
	S.C: O(n)
*/
    int m = grid.length;
    int n = grid[0].length;
    
	//at each row>=1 we need value from prevRow and currRow
    int[] prevRow = new int[n];
    prevRow[0] = grid[0][0];
    
	//setting the prevRow for first row
    for(int i=1; i<n; i++){
        prevRow[i] = prevRow[i-1] + grid[0][i];
    }
    
    
    //general case
    for(int i=1;i<m; i++){
	//for each row>=1, we maintain a currRow[n]
        int[] currRow = new int[n];
        currRow[0] = grid[i][0]+prevRow[0];
        for(int j=1; j<n; j++){
		//calculate up and left value for (i,j) cell 
            int up = grid[i][j]+ prevRow[j];
            int left =  grid[i][j]+currRow[j-1];
            currRow[j] = Math.min(up, left);
            
        }
		//make currRow as prevRow for next row
        prevRow = currRow;
    }
    
	//final ans in ( n-1)th column of prevRow
    return prevRow[n-1];
    
}


private int minPathTabulation(int[][] grid){
	/* T.C: O(m*n)
	S.C: O(m*n)
*/
    int m = grid.length;
    int n = grid[0].length;
    int[][] dp = new int[m][n];
    
    //base cases
    
    dp[0][0] = grid[0][0];
    for(int i=1; i<m; i++){
        dp[i][0] = dp[i-1][0]+grid[i][0];
    }
     for(int i=1; i<n; i++){
        dp[0][i] = dp[0][i-1]+grid[0][i];
    }
    
    
  //general case
    for(int i=1;i<m; i++){
        for(int j=1; j<n; j++){
            int up  = grid[i][j]+ dp[i-1][j];
			int left = grid[i][j]+ dp[i-1][j];
			dp[i][j] = Math.min(up, left);
        }
    }
    
    return dp[m-1][n-1];
    
}

private int minPathRecurMemo(int r, int c, int[][] grid, int[][] dp){
			/* T.C: O(2^(m*n))
			 S.C: O(m + n ) + O(m*n)
			*/
    if(r<0 || c<0 ){
        return 100000000;
    }
    
        if(r==0 && c==0){
            return grid[0][0];
        }
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    
    int up = grid[r][c] + minPathRecurMemo(r-1, c, grid, dp);
    int left = grid[r][c] +minPathRecurMemo(r, c-1, grid, dp);
    return dp[r][c] = Math.min(up, left);
}
public int minPathSum(int[][] grid) {
    
    int m = grid.length;
    int n = grid[0].length;
    
    int[][] dp = new int[m][n];
    
    for(int[] rowArr : dp){
        Arrays.fill(rowArr, -1);
    }
    // return minPathRecurMemo(m-1, n-1, grid, dp);
   // return minPathTabulation(grid);
    return minPathOptimalSpace(grid);
    
    
}
}
