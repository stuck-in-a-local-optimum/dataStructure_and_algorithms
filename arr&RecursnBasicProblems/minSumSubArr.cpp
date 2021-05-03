#include <iostream>

using namespace std;

        /*------MINIMUM SUBARRAY SIZE------

        for a given array and an integer X, find the minimum
        subarray size of which sum>x
        */

       /*STRATEGY 
       1) maintain variable ans, currSum & start  (sliding window approach)
       2) iterate over array & start adding elements to currSum
       3) if currSum>X, remove elements from the start
                O(n)
       */


        int smallestSubArrWithSum(int arr[], int n, int x){
            int currSum=0;
            int minSubArrLenght=n+1;  //ans variable, initialized to undesired value
            int start=0; int end=0;

            while( end<n){

                    //keep adding to currSum till >x
                    while(currSum<=x && end< n){
                        currSum+=arr[end++];
                    }


                    //if currSum exceeds x then corresponding minSubArrLength can be the ans
                    //now keep subtracting from start and look for better solution in other subArrays
                    while( currSum > x && start<n){
                        if(end-start<minSubArrLenght){
                             minSubArrLenght = end-start;
                        }
                               currSum-=arr[start++];

                    }
            }

            return minSubArrLenght;



        }











int main(){
        int arr[] = {1, 4, 45, 6, 10, 19};
        int x=51;
        int n=6;

        int minLenght = smallestSubArrWithSum(arr, n, x);

        if(minLenght==n+1){
            cout<<"No such subarray exists"<<endl;
        
        }
        else{
            cout<<"required smallest subrray length is :"<<smallestSubArrWithSum(arr, n, x)<<endl;
        }


    return 0;
}