
                    /*---------TARGET SUM-------
                    we observe that we need to divide the given arr into two subarrays such that
                        diff = s1-s2 = target
                            or s1 = target+s2 = target + sum - s1 
                            or s1 = (target + sum)/2
                            so if we find a subset s1 such that its sum= (target + sum)/2, we just need to count such subsets
                                so it become simple subset sum problem and we are done!

                    
                
                    */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        
        if(sum<target || (long)(sum+target)%2==1){
            return 0;  //not possible
        }
        int s1 = (sum+target)/2;
        
        int dpTable[n+1][s1+1];
        
        for(int row=0; row<=n; row++){
            dpTable[row][0] = 1;
        }
        
        for(int col=1; col<=s1; col++){
            dpTable[0][col] = 0;
}
        
            for(int i=1; i<=n; i++){
                for(int j=1; j<=s1; j++){
                    if(nums[i-1]>j){
                        dpTable[i][j] = dpTable[i-1][j];
                    }
                    else{
                        dpTable[i][j] = dpTable[i-1][j] + dpTable[i-1][j-nums[i-1]];
                        
                    }
                }
            }
        
        return dpTable[n][s1];
       
}
};