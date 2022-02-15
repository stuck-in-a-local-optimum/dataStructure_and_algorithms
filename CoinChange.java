class Solution {
    
    
    public int coinChangeTabMostOptimal(int[] coins, int target){
         
        int n = coins.length;
        
        int[][] dp = new int[n][target+1];
        int[] prev = new int[target+1];
        
        
        //base cases
      
        for(int k=0; k<=target; k++) {
            if( k%coins[0]==0){
                prev[k] = k/coins[0];
            }
            else{
                prev[k] = 1000000000;
            }
        }
        
        
        for(int i=1; i<n; i++){
            int[] curr = new int[target+1];
            curr[0] = 0;
            for(int j=1; j<=target; j++){
                int notPick = 0+prev[j];
                int pick = 1000000000;
                if(coins[i]<=j){
                    pick = 1 + curr[j-coins[i]];  //one coins picked
                    
                }
                
                curr[j] = Math.min(pick, notPick);
            }
            
            prev = curr;
           
        }
        
        return prev[target];
        
        
    }
    
    public int coinChangeTab(int[] coins, int target){
        //T.C: O(n*target)
        //S.C: O(n*target)   //we can still do better and solve it in linear space 
        int n = coins.length;
        
        int[][] dp = new int[n][target+1];
        
        
        //base cases
        for(int k=0; k<=target; k++) {
            if( k%coins[0]==0){
                dp[0][k] = k/coins[0];
            }
            else{
                dp[0][k] = 1000000000;
            }
        }
        
        
        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){
                int notPick = 0+dp[i-1][j];
                int pick = 1000000000;
                if(coins[i]<=j){
                    pick = 1 + dp[i][j-coins[i]];  //one coins picked
                    
                }
                
                dp[i][j] = Math.min(pick, notPick);
            }
        }
        
        return dp[n-1][target];
        
    }
    
    
    public int coinChangeRecurMemo(int[] coins, int idx, int target, int[][] dp){
        if(idx==0){
            if(target%coins[idx]==0){
                return target/coins[0];
            }
            return 1000000000;
        }
        
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
      
        
        int notPick = coinChangeRecurMemo(coins, idx-1, target, dp);
         int pick = 1000000000;
        
        if(coins[idx]<=target){
         pick = 1+coinChangeRecurMemo(coins, idx, target-coins[idx], dp);
        }
        
        return dp[idx][target]= Math.min(pick, notPick);
        
    }
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        
//         int[][] dp = new int[n][amount+1];
        
//         for(int[] row :dp){
//             Arrays.fill(row, -1);
//         }
//         int ans = coinChangeRecurMemo(coins,  coins.length-1, amount,dp);
        
//         if(ans>=1000000000){
//             return -1;
//         }
//         return ans;
        
        
        // int ans = coinChangeTab(coins, amount);
        int ans = coinChangeTabMostOptimal(coins, amount);
                if(ans>=1000000000){
            return -1;
        }
        return ans;
    }
}
