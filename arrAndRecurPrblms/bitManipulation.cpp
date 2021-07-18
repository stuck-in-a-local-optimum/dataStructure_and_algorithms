#include <iostream>
using namespace std;

        int getBit(int n , int pos){
                return (n & (1<<pos))!=0;
        }

        int setBit(int n, int pos){
                return (n | (1<<pos));
        }

        int clearBit(int n, int pos){

                int mask = ~(1<<pos);  //1's complement of 1<<pos
                return (n & mask);
        }

        int updateBit(int n, int pos,int value){
                //update is just clear and set
                int mask = ~(1<<pos);  
                 n = n & mask; //bit at pos cleared

                //now set
                return n | value<<pos;
        }

        bool isPowerOf2(int n){

                return (n & 1)==0;
                
        }

        int noOfOnes(int n){
                int count=0;

                while(n!=0){
                        n = n & (n-1);
                        count++;
                }
                return count;
        }

        void allSubsets(int arr[], int n){

                for(int i=0; i< (1<<n); i++){   //1<<n--> 2^n
                        for(int j=0; j<n; j++){
                                if( i & (1<<j)){  //if jth bit of i is 1
                                        cout<<arr[j]<<" ";

                                }
                        }
                        cout<<endl;  }}

        int uniqueElement(int arr[], int n){
                int xorSum = 0;

                for(int i=0; i<n; i++){
                        xorSum = xorSum^arr[i];
                }
                return xorSum;
        }

        // int twoUniqueElements(int arr[], int n){
        //         int xorSum=0;

        //         for(int i=0; i<n; i++){
        //                 xorSum = xorSum^arr[i];
        //         }
        //         int tempXor = xorSum;  //now using this we need to find both unique numbers


        //         //find the pos of set bit in xorSum
        //         int setBit =0;
        //         int pos=0;

        //         while(setBit!=1){
        //                 setBit= xorSum&1;
        //                 pos++;
        //                 xorSum = xorSum>>1;
        //         }

        //         int newxor=0;

        //         for(int i=0; i<n; i++){
        //                 if(setBit(arr[i], pos-1)){
        //                         newxor = newxor^arr[i];
        //         }
        // }

        // cout<<newxor<<endl;
        // cout<<tempXor^newxor<<endl;
        // }



int main(){

//     cout<<getBit(5, 2)<<endl;
//     cout<<setBit(5, 1)<<endl;

//     cout<<clearBit(5, 2)<<endl;
//     cout<<updateBit(5, 1, 1)<<endl;

    cout<<isPowerOf2(5)<<endl;
    cout<<noOfOnes(19)<<endl;

    int arr[4] = {1, 2, 3, 4};
    allSubsets(arr, 4);

        cout<<endl;
    int arr2[7] = {1,2,3,4,1,2,3};
        cout<<uniqueElement(arr2, 7);






    return 0;
}