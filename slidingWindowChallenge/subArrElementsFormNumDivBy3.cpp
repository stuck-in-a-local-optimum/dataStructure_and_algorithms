#include <iostream>
#include <vector>
using namespace std;


        /*----------SubArr sum divisible by 3-------------

        For a given array and an integer k, check if any subarray of size k 
        exists in the array such that elements in the subarray form
        a number divisible by 3.

        e.g:
            arr = [8, 23, 45, 12, 56, 4]
            k = 3


            then subarray = [12, 56, 4] = 12564 which is divisible by 3
            
            */

           /*--------STRATEGY--------
           FACT: we will use the fact that a number is divisible by 3 if sum of its all digits 
                    is divisible by 3
            1) calcualte sum of first k elements of the array
            2) use sliding window technique and one by one, start subtracting elements
                from start and adding from the end 
            3) At each step, check if sum is divisible by 3 or not. If it is,
                then print the elements.

                O(n)
           
           */

          void computeNumFromSubArr(vector<int> arr, int k){
              //initializing variables
              int currSum=0;
              pair<int , int> ans;

              //calculate sum of first k subarrays
              for(int idx=0; idx<k; idx++){
                  currSum+=arr[idx];
              }

              bool found= false;

                //check 
              if(currSum%3==0){
                  found = true;
                  ans = make_pair(0, k-1);
              }

              //iterate over other elements and keep checking other k size
              //subarrays by subtracting first element and adding next element to the currSubArray

              for(int idx=k; idx< arr.size(); idx++){

                  if(found){
                      break;  //if already found then break
                  }
                  currSum-=arr[idx-k];  //excluding first element from curr subrray
                  currSum+=arr[idx];   //including next element to the curr suabrray

                  if(currSum%3==0){
                      found = true;
                      ans = make_pair(idx-k+1, idx);

                  }

              }

                //if no such subarray exists
              if(!found){
                  ans = make_pair(-1, 0);  //give some invalid ans
              }

              if(ans.first == -1){
                  cout<<"No such subarray exists"<<endl;
              }
              else{
                  //print the elements of the subarray
                  for(int i=ans.first; i<= ans.second; i++){
                      cout<<arr[i]<<" ";
                  }

                  cout<<endl;
              }

          }










int main(){

    vector<int> arr = {84, 23, 45, 12, 56, 82};
    int k=3;

    computeNumFromSubArr(arr, k);



    return 0;
}