#include <iostream>
#include <vector>
using namespace std;


    /*-------PROBLEM STATEMENT-----------------
            Given weights and values of n items, put these items in 
            a knapsack of capacity W to get the maximum total value 
            in the knapsack. In other words, given two integer arrays
            val[0..n-1] and wt[0..n-1] which represent values and weights
            associated with n items respectively. Also given an integer W
            which represents knapsack capacity, find out the maximum value
            subset of val[] such that sum of the weights of this subset is 
        smaller than or equal to W. You cannot break an item, either pick the complete 
        item or don’t pick it (0-1 property)

    */

   /* -----------non-dp RECURSIVE SOLUTION------------------
   //base cases:
    if N===0 || W==0
            return 0;
   for each wt[i]:
        if( wt[i]>W(available space))
                then skip this item
        else
                max( when this item is included, when this item is excluded);
   */

  //COMPLEXITY O(2^n)     //we are computing subproblems again & again and for each item choice for each item to include it or not!

  int recurknapSack(int val[], int wt[], int w, int n){
        if(n==0 || w==0){
            return 0;
        }

            if(wt[n-1]>w){
                return recurknapSack(val, wt, w, n-1);
            }
            
                return max( recurknapSack(val, wt, w-wt[n-1], n-1)+ val[n-1], recurknapSack(val, wt, w, n-1));
}




/*----------(Recursive + memoization approach),the DP-solution----

    MEMOIZATION: Storing past results and reusing it so as to not 
                    repeat expensive computataions.

    we will use a table to store results of subproblem to avoid their computation again
    & again.
    if table[w][n]!--1 then return table[w][n]
        else compute the value and store at table[w][n]
    


    COMPLEXITY: O(n*w)  
    MEMOIZATION PROBLEMS: 
            1) EXTRA SPACE
            2) STACK OVERFLOW (recursion uses stack and hence stack overflow can occur for lage inputs)

            so we prefers iterative approach (top-down approach)!

*/

int dpknapSack(int val[], int wt[], int w, int n){
        if(n==0 || w==0){
            return 0;
        }

        int table[n][w];
        for(int i=0;i<n;i++){            //initializing the table
            memset(table[i],-1, sizeof(int)*w);
        }

        int result;

        if(table[n-1][w-1]!=-1){
            return  table[n-1][w-1];
        }
        else{
        

                    if(wt[n-1]>w){
                        result= dpknapSack(val, wt, w, n-1);
                    }
                    
                        result = max( dpknapSack(val, wt, w-wt[n-1], n-1)+ val[n-1], dpknapSack(val, wt, w, n-1));
}

table[n-1][w-1] = result; //update the table value

return result;
}



/*------------another DP approach, TOP-DOWN method--------
        1) in purely recursive approach, we were doing only 'function calls'
        2) in recursive + memoization approach, we were using   'function calls'+ 'table'
        3) in iterative top-down approach we will only be filling 'table'

        */

       int tabulationKnapSack(int val[], int weights[], int w, int n){
           

           int dpTable[n+1][w+1];

           for(int item=0; item<=n; item++){
               for(int wt=0; wt<=w; wt++){
                   if(item==0 || wt==0){   //base cases
                       dpTable[item][wt] = 0;

                   }
                   //if the weight of current item is more than the capacity then skip this item
                   else if( weights[item-1]>w){         //item-1 because weight array is 0 index based, so current items weight is at index item-1 in weights array, same for values array
                       dpTable[item][wt] = dpTable[item-1][wt];       //item skipped
                   }
                   else{
                       dpTable[item][wt] = max(dpTable[item-1][wt-weights[item-1]]+ val[item-1] ,dpTable[item-1][wt]);   //when item included, we need to add value of current item to the result of above cell , val[item-1] gives value of current item (0-indexing)
                   }

               }
           }

           return dpTable[n][w];  //final ans is in the last cell
       }


int main(){

    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << recurknapSack(val, wt, W, n)<<"\n";
    cout<<dpknapSack(val, wt, W, n)<<"\n";
    cout<<tabulationKnapSack(val, wt, W, n)<<"\n";



    return 0;   
}