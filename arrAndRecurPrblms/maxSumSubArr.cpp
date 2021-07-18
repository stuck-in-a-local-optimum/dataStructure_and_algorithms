#include <iostream>
using namespace std;



        /*------MAXIMUM SUM SUBARRAY------------

        For a given array and integers K & X, find the maximum sum
        subarray of size K and having sum less than X.
        */


       /*  ------STRATEGY----- O(n)
       1) calculate sum of first k elements
       2) initialize ans with this sum
       3) interate over the rest of the arr,
                keep adding one element in sum and removing one from start
                compare new sum with ans in each interation
       */


      void maxSubArrSum( int arr[], int n, int k, int x){

          int sum=0; int ans=0;

          for(int idx=0; idx<k; idx++){  //calculating sum of first k elements
              sum+=arr[idx];
          }

          if(sum<x){   //check this sum is viable or not
              ans = sum;  //update if yes
          }

          for(int idx=k; idx<n; idx++){  //keep iterating over other elements

              sum-=arr[idx-k];    //exclude starting element of currSubarray 
              sum+=arr[idx];       //include next element to currSubarray

                 if(sum< x){
              ans = max(ans, sum);
          }
          
          }

          if(sum< x){
              ans = max(ans, sum);
          }

          cout<<ans<<" is the max subarray sum (<x)" <<endl;

      }





int main(){

    int arr[] = {7,5, 4, 6, 8 , 9};

    int k=3;
    int x=20;
    int n=6;

    maxSubArrSum(arr, n, k, x);



    return 0;
}