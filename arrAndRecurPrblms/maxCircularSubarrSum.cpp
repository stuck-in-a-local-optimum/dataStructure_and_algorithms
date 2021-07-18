#include <iostream>
using namespace std;


int kadanes(int arr[], int n){

    int maxSum = INT_MIN;
    int currSum=0;
    
    for(int i=0; i<n; i++){
        currSum+=arr[i];

        if(currSum<0){
            currSum=0;
        }
        maxSum = max(maxSum, currSum);
    }

    return maxSum;

}


int main(){

    /*
        need to look two cases:
        case1: when wrapping not required
        solution: simple kadane's algo

        case2: wraping required!
        solution: 
        maxSubArrsum = total sum of array - sum of non-contributing elements

        At the end we need to take max of both cases
    */

   int n;
   cin>>n;

int arr[n];

for(int i=0; i<n; i++){
    cin>>arr[i];

}

int wrappingSum = INT_MIN;
int nonWrappingSum = INT_MIN;

 nonWrappingSum = kadanes(arr, n);


//find sum of non-contributing elements
//if wrapping then non-contributing elements will be non-wrapping
//and since kadane gives sum of non-wrapping contributing elements
//so to find sum of non-contributing wrapping elements we reverse the sign of
//each element in the array and apply kadanes

    int totalArrrSum = 0;
for(int i=0; i<n; i++){
    totalArrrSum+=arr[i];
    arr[i] = -arr[i];

}


wrappingSum = totalArrrSum - (-kadanes(arr, n));

cout<<max(wrappingSum, nonWrappingSum)<<endl;








    return 0;
}