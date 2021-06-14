#include <iostream>
using namespace std;


            /*------A SUBSET OF SUM EQUAL TO GIVEN VALUE EXISTS OR NOT*/


    bool isSubSetSumRecur(int set[], int n, int  sum){
        if(sum==0){  //we can achieve this sum by excluding all elements
            return true;
        }

        if(n==0 & sum!=0){
            return false;
        }

        if(set[n-1]> sum){
            return isSubSetSumRecur(set, n-1, sum);  //need to exclude this element
        }
            return isSubSetSumRecur(set, n-1, sum) || isSubSetSumRecur(set, n-1, sum-set[n-1]);  //else check either by including or excluding
    
        
    }


    bool isSubSetSumDp(int set[], int n, int sum){
        int dpTable[n+1][sum+1];


        for(int i=0; i<=n; i++){   //when sum is 0, then ans is true
            dpTable[i][0] = true;
        }

        for(int i=1; i<=sum; i++){
            dpTable[0][i] = false;  //when no element in set, then ans is false
        }

        for(int item=1; item<=n; item++){

            for(int sm=1; sm<=sum; sm++){
                if(set[item-1]> sm){
                    dpTable[item][sm] = dpTable[item-1][sm];
                }
                else{
                    dpTable[item][sm] = dpTable[item-1][sm] || dpTable[item-1][sm-set[item-1]];
                }

            }

        }

        return dpTable[n][sum];
    }











int main(){
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum=9;
    int n = sizeof(set)/sizeof(set[0]);

    cout<<isSubSetSumRecur(set, n, sum)<<"\n";
    cout<<isSubSetSumDp(set, n, sum)<<"\n";



    return 0;
}