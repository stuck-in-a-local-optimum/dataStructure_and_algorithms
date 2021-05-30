
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        int dpTable[n+1][amount+1];
        
        for(int row=0; row<=n; row++){
                dpTable[row][0] = 1;   //we can make given amount=0 in one way, by excluding all the coins
            
                }
        
        for(int col=1; col<=amount; col++){
            dpTable[0][col] = 0;            //we no. of coins is 0, then we can't make the given amount by any combination
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if( coins[i-1] > j){
                    dpTable[i][j] = dpTable[i-1][j];        //reject this coin
                }
                else{
                    dpTable[i][j] = dpTable[i-1][j] + dpTable[i][j-coins[i-1]];   //otherwise count all possible ways be excluding and including a coin
                }
            }
        }
        
        return dpTable[n][amount];
        
        
        
    }
};