#include <iostream>
using namespace std;

//Q1 Output sum of all the subarrays of an array

void subArraySum(int arr[], int n){
    for(int i=0; i<n; i++){
            int subArraySum=0;

        for(int j=i; j<n; j++){
            subArraySum+=arr[j];
            cout<<subArraySum<<endl;
        }
    }
}

//Q2 Longest arithematic Subarray
/*
An arithematic array is an array that contain at least two integers and the difference between consecutive integers are equal.
 For example [9, 10], [3,3,3], and [9,7,5,3] are arithematic arrays, while [1, 3,3,7], [2,1,2] and [1,2,4] are not arithmetic arrays.
Sarasvati has an array of N non-negative integers. The ith integer of the array is Ai. She wants to choose a contigous arithmetic subarray 
from her array that has the maximum lenght. 
Please help her to determine the length of the  longest contigous arithmetic subarray.

INPUT
The first line of the input gives the number of test cases, T. T test cases follow.
Each test case begins with a line containing the integer N. 
The second line contains N integers. The i-th integer is Ai.

OUTPUT
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the length of the 
longest contiguous arithmetic subarray.

CONSTAINTS:  1 ≤ T ≤ 100. 0 ≤ Ai ≤ 10^9
*/

void q2(int arr[], int n){
        int ans=2;
        int pDiff=arr[1]-arr[0];
        int curr=2;

            for(int i=2; i<n; i++){

                if(pDiff == arr[i]-arr[i-1]){
                    curr+=1;
                }
                else{
                    pDiff = arr[i]-arr[i-1];
                    curr =2;
                }
                ans= max(ans, curr);
            }

            cout<<ans<<endl;
}


//Q3 RECORD BREAKING DAY
/*
Isyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on the i-th day is Vi. 
A day is record breaking if it satisfies both of the following conditions:

i) The number of visitors on the day is strictly larger than the number of visitors on each of the previous days.

ii) Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.
Note that the very first day could be a record breaking day!
Please help Isyana find out the number of record breaking days.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the integer N. 
The second line contains N integers. The i-th integer is Vi.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of record breaking days.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
0 ≤ Vi ≤ 2 × 10^5.
    */


   void q3(int arr[], int n){
       int mx=-1;
       int ans=0;


       for(int i=0; i<n-1; i++){
           if(arr[i] > mx && (arr[i]>arr[i+1])){
               mx =max(mx, arr[i]);
               ans++;
           }
   }
   if(arr[-1]>mx){
       ans+=1;
   }
   cout<<ans<<endl;
   }

int main(){
    int n;
    cout<<"Enter value of n"<<endl;
    cin>>n;

    int arr[n];
    

    cout<<"Enter elements of array space seperated"<<endl;

      for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //subArraySum(arr, n);
    //q2(arr, n);
    q3(arr, n);

}