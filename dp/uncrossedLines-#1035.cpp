//-------LONGEST COMMON SUBSEQUENCE APPROACH-----

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int dpTable[n1+1][n2+1];
        
        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                if(i==0 || j==0){
                    dpTable[i][j] = 0;  //can't form any line in this case
                }
                else if( nums1[i-1]==nums2[j-1]){
                    dpTable[i][j] = 1+dpTable[i-1][j-1];  //draw new line
                    
                }
                else{
                    dpTable[i][j] = max( dpTable[i-1][j], dpTable[i][j-1]);  //else take max of that L and inverted L configuration
                }
            }
        }
        return dpTable[n1][n2];
        
    }
};