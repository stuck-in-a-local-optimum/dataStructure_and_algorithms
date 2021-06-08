//LEETCODE 221


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int largest =  0;
        
        int dpTable[m][n];
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0){
                    dpTable[i][j] = matrix[i][j]-'0';
                     largest = max(largest, dpTable[i][j]);

                }
                else if(matrix[i][j]=='0'){
                    dpTable[i][j] = 0;
                    
                }
                else{
                    int firstMin =  min(dpTable[i-1][j], dpTable[i-1][j-1]);
                    dpTable[i][j] = 1 + min( firstMin, dpTable[i][j-1]);
                     largest = max(largest, dpTable[i][j]);
                    
                }
            }
        }
        
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cout<<dpTable[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return largest*largest;
        
    }
};