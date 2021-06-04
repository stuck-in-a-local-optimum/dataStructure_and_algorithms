#include <iostream>
using namespace std;



        int longestIncreasingSubsq(int arr[], int n){
            int lis[n];

            lis[0] = 1;  //at the begining each element is longestIncreasingSubseq of size 1

            for(int i=0; i<n; i++){
                lis[i] = 1;

                for(int j=0; j<i; j++){         //for each element start checking from 0th element
                    if(arr[i]>arr[j] && lis[i]<lis[j]+1){ //lis[i]<lis[j]+1 because our next element in LISubq should have 1 index greater tha prev element in LIsubq
                        lis[i] = lis[j]+1;  //if the ith index is feasible then assign it next index in lis (1 based indexing which actually refers the size of the LISubsq)
                    }
                }
            }

                //return the maximum value in lis[]
                return *max_element(lis, lis+n);
            
        }





int main(){

    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Length of lis is %d\n", longestIncreasingSubsq( arr, n ) ); 
	return 0;
}