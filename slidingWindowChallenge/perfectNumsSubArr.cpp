#include <iostream>
#include <cmath>
using namespace std;


        /*--------PERFECT NUMBERS IN SUBARRAYS----------

                for a given array and an integer k, find the maximum no.
                perfect numbers in a subarry of size k.
        
        */


       //PERFECT NUMBERS : Perfect number is a number if it is equal to the sum of its
        //                    proper divisors (+ve divisor) except for the no. itself.
        //e.g 6  ---> [1, 2, 3]

        /*----------------STRATEGY-----------O( n* sqrt(n))

        1) trick: first we convert the given array into a binary array with 
                values 0 & 1, i.e at each index i,if arr[i] is perfect no. then
                replace it with 1 else with 0

         2) now our problem reduces to find the maxSum subarray of size k which can easily 
            be found be sliding window technique :) 



        --------isPerfectNumber function-----
                1) intitializs variable to store sum of divisors so far.
                2) traverse every number less than sqrt( arr[i]) ad add it to
                    currDivisorSum if it is a divisor of arr[i]
                    3) if currDivisorSum==n, then arr[i] is perfect number else not

        */





        bool isPerfectNumbr(int a){
            int currDivSum = 1;

            for( int i=2; i< sqrt(a); i++){
                if( a%i == 0){
                    if(i == a/i){
                        currDivSum+=i;

                    }
                    else{
                        currDivSum += i + a/i;
                    }
                }
            } 

            if( currDivSum == a && a!=1){
                return true;
            }
            return false;

           }

           int maxSum(int arr[], int n, int k){

               if(n < k){
               cout<<"INVALID VALUES"<<endl;

               return -1;
           }

               //now find the maximum sum sub array o size k using two pointet technique
                int currSum = 0; int ans;

                
                for(int i=0; i<k; i++){
                    currSum+=arr[i];
                    
                }

                ans = currSum;

                //traverse rest of the array to find better subarray

                for( int i=k; i<n; i++){
                    currSum-=arr[i-k];
                    currSum+=arr[i];

                    currSum = max(currSum, ans);
                }

                return ans;

           }


       int maxNumOfPerfects(int arr[], int n, int k){
    
            //convert the array to binary array so that if arr[i] is perfect no.
            //then replace it with 1 else with 0
            for(int index=0; index< n; index++){
                if(isPerfectNumbr(arr[index])){
                    arr[index] = 1;
                }
                else{
                    arr[index] = 0;
                }
            }


            return maxSum(arr, n, k);

        
       }




int main(){

    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k=4;
    int n=8;

    cout<< maxNumOfPerfects(arr, n, k)<<endl;



    return 0;
}