#include <iostream>
using namespace std;


int main(){

    int n1, n2, n3;
        cin>>n1;
        cin>>n2;
        cin>>n3;
        int arr1[n1][n2];

         int arr2[n2][n3];
         int arr3[n1][n3];
        


        for(int row=0; row<n1; row++){
            for(int col=0; col<n2; col++){
                cin>>arr1[row][col];
            }
        }

        for(int row=0; row<n2; row++){
            for(int col=0; col<n3; col++){
                cin>>arr2[row][col];
            }
        }

         for(int row=0; row<n1; row++){
            for(int col=0; col<n3; col++){
            arr3[row][col]=0;
            }
        }

        

        //brute force
        for(int i=0; i<n1; i++){
            for(int j=0; j<n3; j++){
                for(int k=0; k<n2; k++){
                    arr3[i][j] += arr1[i][k]*arr2[k][j];
                }
            }
        }

        for(int row=0; row<n1; row++){
            for(int col =0; col<n3 ; col++){
                cout<<arr3[row][col]<<" ";

            }
            cout<<endl;
        }







    return 0;
}