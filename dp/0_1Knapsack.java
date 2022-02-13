import java.util.*;
public class 0_1Knapsack{
    
    static int knapsackDpTabMostOptimised(int[] W, int[] V, int w, int n){
//           int[][] dp = new int[n][w+1];
        
        //base cases
        int[] prev = new int[w+1];
       
        for(int j=0; j<=w; j++){
            if(W[0]<=j) prev[j] = V[0];
        }
       
        for(int i=1; i<n; i++){
            int[] curr = new int[w+1];
            curr[0] = 0;
            for(int j=1; j<=w; j++){
                
                int notPick = prev[j];
                int pick = -10000000;
                if(W[i]<=j){
                    pick = V[i] + prev[j-W[i]];
                    
                }
                
                curr[j] = Math.max(notPick, pick);
            }
            
            prev = curr;
        }
        
        return prev[w];     
        
    }
    
    static int knapsackDpTab(int[] W, int[] V, int w, int n){
        int[][] dp = new int[n][w+1];
        
        //base cases
        for(int j=0; j<=w; j++){
            if(W[0]<=j) dp[0][j] = V[0];
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<=w; j++){
                
                int notPick = dp[i-1][j];
                int pick = -10000000;
                if(W[i]<=j){
                    pick = V[i] + dp[i-1][j-W[i]];
                    
                }
                
                dp[i][j] = Math.max(notPick, pick);
            }
        }
        
        return dp[n-1][w];     
    }
    
    static int knapsackRecurMemo(int[] weights, int[] values, int[][] dp, int idx, int w){
        if(idx==0){
            if(weights[0]<=w) return values[0]; //pick the item
            else return 0; //can't pick
        }
        
        if(dp[idx][w]!=-1){
            return dp[idx][w];
        }
            int notPick = 0+ knapsackRecurMemo(weights, values, dp, idx-1, w);
            int pick = -100000000;
            if(weights[idx]<=w){
                pick = values[idx] + knapsackRecurMemo(weights, values, dp, idx-1, w-weights[idx]);
            }
        
        
        return dp[idx][w] = Math.max(notPick, pick);  
    }
    
    
    static int knapsack(int[] weight, int[] value, int n, int maxWeight) {

            /* Your class should be named Solution
            * Don't write main().
            * Don't read input, it is passed as function argument.
            * Change in the given tree itself.
            * No need to return or print the output.
            * Taking input and printing output is handled automatically.
            */
        
        int[][] dp = new int[n][maxWeight+1];
        
        for(int[] row:dp){
            Arrays.fill(row, -1);
        }
        
//         return knapsackRecurMemo(weight, value, dp,n-1, maxWeight);
//         return knapsackDpTab(weight, value, maxWeight, n);
        
        return knapsackDpTabMostOptimised(weight, value, maxWeight, n);

    }
}


