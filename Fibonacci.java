public class Fibonacci {
    public static void main(String args[]) {
        
        int n=7;
        System.out.println(fibonacci(n));
        
        int[] dp = new int[n+1];
        for(int i=0; i< n+1; i++){
            dp[i] = -1;
        }
        
        System.out.println(fibMemoization(n, dp));
        System.out.println(fibTabulation(n, dp)); 
        
        System.out.println(fibTabOptimised(n));
      
    }
    
    
    //Memoization, T.C O(n), S.C- O(n) for dp[] + O(n) recursive stack === O(n)
    public static int fibonacci(int n){
        if(n<=1) return n;
        
        return fibonacci(n-1) + fibonacci(n-2);
    }
    
    public static int fibMemoization(int n, int[] dp){
        if(n<=1) return n;
        
        //check of already calculted
        if(dp[n]!=-1){
            return dp[n];
        }
        
        //if not alredy calculated means we are calculating it first time
        //so compute and store it
        return dp[n] = fibMemoization(n-1, dp) + fibMemoization(n-2, dp);
    }
    
    
    
    //tabulation method bottom-up (base case to n) appraoch, T.C: O(n) , S.C.: O(n)
    public static int fibTabulation(int n, int dp[]){
        
    
        //base cases
        dp[0]= 0;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
            
        }
        
        return dp[n];
    }
    
    
    
    //We still can do better, we can improve the space complexity further
    public static int fibTabOptimised(int n){
        int prev2 = 0;
        int prev1 = 1;
        
        for(int i=2; i<=n; i++){
           int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    
    
}
