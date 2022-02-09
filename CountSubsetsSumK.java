public class CountSubsetsSumK {
    	
    public static int solveTabDpMostOptimised(int[] num, int k){
        //T.C: O(num*k)
        //S.C: O(n)
        int n = num.length;
    
        
        //base cases1
//         for(int i=0; i<n; i++) dp[i][0] = 1;
        
        //base case2
//         if(num[0]<=k){
//         dp[0][num[0]]=1;
//         }
        
        int[] prev = new int[k+1];
        //base case1
        prev[0]=1;
        
        //base case2
         if(num[0]<=k){
        prev[num[0]] = 1;
         }
        
        for(int i=1; i<n; i++){
            int[] curr = new int[k+1];
                curr[0] = 1;
            for(int j=1; j<=k; j++){
                
                int notTake = prev[j];
                int take = 0;
                if(num[i]<=j){
                 take = prev[j-num[i]];
            }
                
                curr[j] = notTake+take;
            }
            prev = curr;
        }
        
        return prev[k];
        
    }
    
    public static int solveRecurMemo(int num[], int idx, int tar){ 
        if(idx==0){
            if(tar==0){
            return 1;
        }
            if(num[idx]==tar){
                return 1;
            }
            return 0;
        }
        
        
        
        
       int take =0;
       int notTake = solveRecurMemo(num, idx-1, tar);
        
        if(num[idx]<=tar){
        take = solveRecurMemo(num, idx-1, tar-num[idx]);
        }
        
        return notTake + take;
        
        
    }
    public static int findWays(int num[], int tar) {
        // Write your code here..
        int n = num.length;
//         return solveRecurMemo(num, n-1, tar);
        return solveTabDpMostOptimised(num,  tar);
    }
}
