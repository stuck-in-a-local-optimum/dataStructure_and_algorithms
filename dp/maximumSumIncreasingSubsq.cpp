#include <iostream>
using namespace std;

    int maxSumIncSubsq(int arr[], int n){
        int msis[n];

        for(int i=0; i<n; i++){
            msis[i] = arr[i];
            for(int j=0; j<i; j++){
                if(arr[i]>arr[j] && msis[i]< msis[j]+ arr[i]){      //only difference b/w LIS and MSIS is that here we care about the sum of inc. subsq. not length
                    msis[i] = msis[j] + arr[i];
                }
            }
        }


        int maxSum= INT_MIN;

        for(int i=0; i<n; i++){
            if(msis[i] > maxSum){
                maxSum = msis[i];
            }
        }


        return maxSum;
    }




int main(){

    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n=7;

    cout<<maxSumIncSubsq(arr, n)<<endl;


    return 0;
}