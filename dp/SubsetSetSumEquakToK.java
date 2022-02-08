//PROBLEM LINK: https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1
//pick, notPick Dp approach

import java.util.*;
public class Solution {
    private static boolean solveRecurMemo(int idx, int k, int[] arr, int[][] dp){
        if(k==0){
            return true;
        }
        if(idx==0){
            if(k==arr[0]){
                return true;     }
        return false;
        }
        
        //check if already calculated
        if(dp[idx][k]!=-1){
            return dp[idx][k]==1;
        }
        
        
        boolean pick = false;
        boolean notPick = false;
        
        if(arr[idx]<=k){
            pick = solveRecurMemo(idx-1, k-arr[idx], arr, dp);
        }
        notPick = solveRecurMemo(idx-1, k, arr,dp);
        
        if((pick || notPick)==true){
            dp[idx][k]=1;
        }
        else{
            dp[idx][k] = 0;
        }
        return dp[idx][k]==1;
      
    }
	public static boolean subsetSumToK(int n, int k, int[] arr){
		// Write your code here.
        int[][] dp = new int[n][k+1];
        
        for(int[] row : dp){
            Arrays.fill(row, -1);
        }
        
        return solveRecurMemo(n-1, k, arr, dp);
	}
}
