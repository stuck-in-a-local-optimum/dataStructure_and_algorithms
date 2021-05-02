#include <iostream>
#include <algorithm>
using namespace std;


            /*PROBLEM
            Given  an array with n elements that represents n positions
            along a straight line. Find k elements such that the minimum
            distance betweeen any 2 elements is the maximum possible
            */

            /* SOLUTION
             Binary search approach
             0) sort the array
            1) pick middle elements as the result & check for its feasibility.
            2) If feasible, search the right half of the array with larger minimum distance.
            3) else search the left half of the array
            
            */


           bool isFeasible(int mid, int arr[], int n, int k){

               int pos=arr[0];    //always include first element
               int currElements=1;

               for(int i=1; i<n; i++){
                   if(arr[i]-pos>=mid){
                       pos=arr[i];
                       currElements++;
                       if(currElements==k){
                           return true;
                       }
                   }

               }

               return false;

           }

           int largestMinDistance(int arr[], int n, int k){
               sort(arr, arr+n);  //sort the array

               //declaring and initializing variables
                int result = -1;
               int left=1; int right=n-1;

               while(left<right){

                    int mid = (left+right)/2;

                    if(isFeasible(mid, arr, n, k)){
                        result = max(result, mid);
                        left = mid+1;    //look in right half for better answer

                    }
                    else {
                        right = mid;   //look in left half
                    }
               }

               return result;


           }

int main(){

    int arr[] = {1, 8, 2, 9, 4};

    int n=5;
    int k=3;

    cout<<" largest minimum distance is: "<<largestMinDistance(arr, n, k)<<endl;




    return 0;
}