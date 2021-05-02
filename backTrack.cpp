#include <iostream>
using namespace std;


bool isSafe(int** arr, int x, int y, int n){
    if(x<n && y<n && arr[x][y]==1){

        return true;
    }
    return false;
}


/*
A rat stuck in a 0, 1 maze, he wants to reach last cell, 0 cell is obstacle, 1 is safe
output the path of rat with 1 cells if possible to reach at the end

*/

bool ratInMaze(int** arr, int x, int y, int n, int** solArr){

    if(x==n-1 && y==n-1){
        solArr[x][y]=1;
        return true;
    }

    if(isSafe(arr, x, y, n)){
        solArr[x][y] = 1;

        //if path exist from down 
        if(ratInMaze(arr, x+1, y, n, solArr)){
            return true;

        }

        //if path exist from right
        if(ratInMaze(arr, x, y+1, n, solArr)){
            return true;

        
        //if we can't find path by both above ways then reset the cell  (wrong choice!)
        solArr[x][y] = 0;  //backtracking!!
        return false;

        
    }
    return false;
}
}


bool isQueenSafe(int** arr, int x, int y, int n){
        int r1=x; int c1=y;
        while(r1>=0 && c1>=0){
            if(arr[r1][c1]==1){
                return false;
            }
            r1--;
            c1--;
        }

        int r2=x;
        while (r2>=0)
        { if(arr[r2][y]==1){
                return false;
            }
            r2--;
        }

        int c2=y;
                while (c2>=0)
        { if(arr[x][c2]==1){
                return false;
            }
            c2--;
        }

        int r3=x; int c3=y;
        while(r3>=0 && c3<n){
            if(arr[r3][c3]==1){
                return false;
            }
            c3++;
            r3--;

        }
        return true;   

}


bool nQueen(int** arr, int x, int n){

    if(x>=n){   //all queens are placed!
        return true;
    }


    for(int col=0; col<n; col++){
        if(isQueenSafe(arr, x, col, n)){
            arr[x][col] = 1;
            if(nQueen(arr, x+1, n)){
                return true;

            }
            arr[x][col] =0;  //backTracking!!
        }
    }

    return false;
}







int main(){

    // int n;
    // cin>>n;

    // int** arr = new int*[n];   //dynamic memeory allocation


    // for(int i=0; i<n; i++){
    //     arr[i] = new int[n];
    // }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cin>>arr[i][j];
    //     }
    // }

    // int** solArr = new int*[n];

    //      for(int i=0; i<n; i++){
    //     solArr[i] = new int[n];
    //     for(int j=0; j<n; j++){
    //         solArr[i][j] = 0;
    //     }
    // }

    // cout<<endl;

    //     if(ratInMaze(arr, 0, 0, n, solArr)){
    //         for(int i=0; i<n; i++){
    //             for(int j=0; j<n; j++){
    //                 cout<<solArr[i][j]<<" ";
    //             }cout<<endl;
    //         }

    //     }

        int n2;
        cin>>n2;


        int** arr2 = new int*[n2];

        for(int i=0; i<n2; i++){
             arr2[i] = new int[n2];

        }

        for(int i=0; i<n2; i++){
            for(int j=0; j<n2; j++){
                arr2[i][j]=0;
            }
        }


        if(nQueen(arr2, 0, n2)){
            for(int i=0; i<n2; i++ ){
                for(int j=0; j<n2; j++){
                    cout<<arr2[i][j]<<" ";
                }cout<<endl;
            }
        }
        





    return 0;
}