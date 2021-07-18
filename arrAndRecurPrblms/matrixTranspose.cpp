#include <iostream> 
using namespace std;

/*
for transpose we only need to all the elements in the
upper triangle s.t (row, col) => (col, row)
 */



int main(){

        int m,n;
        cin>>m;
        cin>>n;
        int arr[m][n];


        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                cin>>arr[row][col];
            }
        }



        for(int row=0; row<m; row++){
            for(int col =row+1; col<n ; col++){
                int temp = arr[col][row];
                arr[col][row] = arr[row][col];
                arr[row][col] = temp;

            }
        }

        cout<<endl;

        for(int row=0; row<m; row++){
            for(int col =0; col<n ; col++){
                cout<<arr[row][col]<<" ";

            }
            cout<<endl;
        }




    return 0;
}