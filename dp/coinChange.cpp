#include <iostream>
using namespace std;

            /*--------COIN CHANGE PROBLEM--------------
            
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/


    /*-------------The approach---------------
            1) For each coin, we have option to either include or exclude to in making given amount =>KNAPSACK condition
            2) unlike to 0-1 knapsack , here we  have infinite no. of coins of each denominaton => unbounded knapsack
            3) coins used is to be minimum
        */

       //recursive algo
    //    int coinChangeRecur(int coins[],  int n, int a){
    //        //base cases
    //        if(n==0 && a>0){
    //            return INT_MAX;   //can't make required amount

    //        }

    //        if(a==0 && n>0){
    //            return 0;    //we can use 0 coins to make the required amount 'a'
    //        }
        
    //        if( coins[n-1]>a){ 
    //            return coinChangeRecur(coins, n-2, a);   //reject this coin
    //        }
    //        return min( coinChangeRecur(coins, n-2, a) , 1+coinChangeRecur(coins, n-1, a-coins[n-1]));  //take minimum of both ways, by exluding and including

    //    }


       //----------TOP-DOWN DP APPROACH----------

       int coinChangeDp(int coins[],  int n, int a){

           int dpTable[n+1][a+1];    

           //base cases
           for(int i=0; i<=n; i++){
               dpTable[i][0] = 0;  //there is make 0 amount by 0 coins
           }

           for(int j=1; j<=a; j++){
               dpTable[0][j] = INT_MAX;  //we can't make any sum of money of we have 0 coins
           }


           //general case
           for(int i=1; i<=n ; i++){
               for(int j=1; j<=a; j++){
                   if( coins[i-1]> j){
                       dpTable[i][j] = dpTable[i-1][j];   //reject this coin
                   }
                   else{
                       dpTable[i][j] = min( dpTable[i-1][j], 1+ dpTable[i][j-coins[i-1]]);
                   }
               }
           }


           if(dpTable[n][a]==INT_MAX){
               return -1;
           }

           return dpTable[n][a];

       }





int main(){

    int coins[] = {1,2, 5};
    int a = 11;
    int n=3;
    //cout<<coinChangeRecur(coins, n, a);
    cout<<endl;
   cout<<coinChangeDp(coins, n, a)<<endl;





}