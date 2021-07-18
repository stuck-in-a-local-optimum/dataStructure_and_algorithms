// #include <iostream>
// #include <vector>
// using namespace std;



//         /*------SUBARRAY WITH PALINDROMIC CONCATENATON--------

//         For a given array and an integer k, check if any subarray of size k
//         exists in the array such that concatenation of elements form a palidrome
//         */

//        /*-------STRATEGY (SLIDING WINDOW APPROACH)--------
//        1) store concatenation of initial k elements
//        2) iterate over the array & start deleting elements from the 
//             start and adding elements from the end
//        3)At each step, check if concatenation is a palindromic
       
//        */


//       void findPalindromicSubarray(vector<int> arr, int k){  //it return start index if palidromic subrray if any
//             string currStr="";
//             pair<int , int> ans;

//             for(int index=0; index<k; index++){
//                 currStr+=arr[index];
//             }


//             if(isPalindromic(currStr)){
//                 ans = make_pair(0, k-1);

//             }

//             for(int index=k; index< arr.size(); index++){
//                 currStr=currStr.substr(index-k+1);
//                 currStr+=arr[index];

//                 if(isPalindromic(currStr)){
//                     ans = make_pair(index-k+1, k);
//                 }
//             }



//       }






// int main(){



//     return 0;
// }