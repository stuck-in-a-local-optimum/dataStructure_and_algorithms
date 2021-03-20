// #include <iostream>
// using namespace std;


// //all columns and rows are sorted
// /*
//  Algo:
//         1) start from top right element
//         2) if A[r,c] == target return true;
//         3) if A[r,c]> target then c--
//         4) if A[r,c]<target then r++
// */



// int main(){

//           int m,n, target;
//         cin>>m;
//         cin>>n;
//         cin>>target;
//         int arr[m][n];


//         for(int row=0; row<m; row++){
//             for(int col=0; col<n; col++){
//                 cin>>arr[row][col];
//             }
//         }


//         bool flag = false;
//         int r= m-1;
//         int c = n-1;
//         while(r<m && c>=0){
//             if(arr[r,c] == target){
//                 flag = true;
//                 c--;
//                break;

//             }
//             else{
//                 r++;
//             }

//         }
//         if(flag){
//             cout<<"element exist";
//         }





//     return 0;
// }
