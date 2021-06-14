#include <iostream>
using namespace std;

            /*-----MNIMUM DIFFERENCE SUBSETS-----
            Divide a given array into two subsets such that
            the difference of their sum  is minimum
            */

            /*-------The approach-------
            1) since one of two subsets is larger than other, so let's assume s1 is less than equal to s2 (s1<=s2)
            2) also we can write s2 in terms of s1 as s2 = sum-s1
            3) now diff = abs(s2-s1)  = abs(sum-2s1) which is supposed to be minimized
            4) to minimize diff, we observe that s1 = [0, sum/2], i.e max value of s1 can be sum/2
            5) so we can form a dpTable by finding all possible subset sums and then minimize the value of diff 
                for s1 in range[0, sum/2]  in nth row of the dpTable

            
            */


int minDiffSubsetDP(int arr[]){


    //setting the subset sum table (i.e findig all possible subset sums of given arr)
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    int dpTable[n+1][sum+1];

    for(int row=0; row<=n; row++){
        dpTable[row][0] = true;
    }

     for(int col=0; col<=sum; col++){
        dpTable[0][col] = false;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]>j){
                dpTable[i][j] = dpTable[i-1][j];
            }
            else{
                dpTable[i][j] =  dpTable[i-1][j] || dpTable[i-1][j-arr[i-1]];
            }

        }
    }

    //minimizing the diff = abs(sum-2s1)
    int diff = INT_MAX;
    for(int i=0; i<=sum/2; i++){
        int s1 = i;
        int s2 = sum-s1;

        if(dpTable[n][i] && diff< abs(s1-s2)){
            diff = abs(s1-s2);
        }
    }

    return diff;

}






int main(){
    int arr[] = {2, 6, 11, 5};

        cout<<minDiffSubsetDP( arr)<<" ";


    return 0;
}