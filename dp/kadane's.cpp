#include <iostream>
using namespace std;

        /*------LARGEST SUM OF CONTIGUOUS SUBARRAY------*/





int kadane(int arr[], int n){
   
    int msf = INT_MIN;        //maxSoFar
    int meh = 0;        //maxEndingHere
    for(int i=0; i<n; i++){
        meh = meh + arr[i];
        if( meh < arr[i]){
            meh = arr[i];
        }

        if(msf < meh){
            msf = meh;

        }
        
    }

    return msf;
}




int main(){

    int arr[] = {-2, -3, 4, -1, -2, 1, 5, 3};

    cout<<kadane(arr, 8);



    return 0;
}