#include <iostream>
using namespace std;



/*---------FIND THE PEAK ELEMENT-----

        for a given array, find the peak element in the
        array.
        Peak element is one which is greater than both, left & right
        neighbour of itself



*/


    int findPeakElement(int arr[], int low, int high, int n){

        int mid = low + (high-low)/2;   //this way mid  always be in Integer range, (low+high)/2 can be out of integer range

            if( (mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid]>=arr[mid+1])){
                return mid;

            }

            if( mid>0 && arr[mid]< arr[mid-1]){
                return findPeakElement(arr, low, mid-1, n);

            }

            else{
                return findPeakElement(arr, mid+1, high, n);
            }
 }


int main(){

    int arr[] = {0, 6, 8, 5, 7, 9};
    int n=6;

    cout<<" peak element index :"<<findPeakElement(arr, 0, n-1, n)<<endl;


    return 0;
}