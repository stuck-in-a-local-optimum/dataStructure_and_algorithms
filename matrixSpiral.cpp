// #include <iostream>
// using namespace std;


// int main(){

//         int m,n;
//         cin>>m;
//         cin>>n;
//         int arr[m][n];


//         for(int row=0; row<m; row++){
//             for(int col=0; col<n; col++){
//                 cin>>arr[row][col];
//             }
//         }



//         int row_start=0;
//         int row_end = m-1;

//         int col_start=0;
//         int col_end = n-1;

//         //print spiral 

//         while (row_start<=row_end && col_start<=col_end){
//             for(int i=col_start; i<=col_end; i++){
//                 cout<<arr[row_start][i]<<" ";
//             }
//             row_start+=1;

//             for(int i=row_start; i<=row_end; i++){
//                 cout<<arr[i][col_end]<<" ";
//             }
//             col_end-=1;

//             for(int i=col_end; i>=col_start; i--){
//                 cout<<arr[row_end][i]<<" ";
//             }
//             row_end-=1;

//             for(int i=row_end; i>=row_start; i--){
//                 cout<<arr[i][col_start]<<" ";
//             }

//             col_start+=1;
            



            
//         }
        



//     return 0;
// }