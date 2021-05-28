#include <iostream>
#include <vector>
using namespace std;




            int countSubSetsRecur(int arr[], int n, int sum){
                
                if(sum==0){
                    return 1;
                }
                if(n==0){
                    return 0;
                }

                if(arr[n-1]>sum){
                    return countSubSetsRecur(arr, n-1, sum);  //reject case
                }
                
                return  countSubSetsRecur(arr, n-1, sum)+countSubSetsRecur(arr, n-1, sum-arr[n-1]);  //by excluding + rejecting
            }


            int countSubSetsDp(int arr[], int n, int sum){
                

                int dpTable[n+1][sum+1];

                for(int row=0; row<=n; row++){   //we can make a subset of sum=0 (phi subset)irrespecitive of no. of elements
                    dpTable[row][0] = 1;
                }

                for(int col=1; col<=sum; col++){  //with 0 elements we can only make a subset of sum=0 (phi subset)
                    dpTable[0][col] = 0;
                }

                for(int item=1; item<=sum; item++){
                    for(int sm=1; sm<=sum; sm++){
                        dpTable[item][sm] = dpTable[item-1][sm] + dpTable[item-1][sm-arr[item-1]];  //store value of each path be it rejection or selection of an element (tree visualization)
                    }
                }


                return dpTable[n][sum];
            }







int main(){
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum=3;
    cout<<countSubSetsRecur(arr, n, sum)<<'\n';
        cout<<countSubSetsDp(arr, n, sum);




    return 0;
}