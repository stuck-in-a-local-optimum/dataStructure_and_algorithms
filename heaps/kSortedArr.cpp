#include <iostream>
#include <queue>
#include <vector>
using namespace std;


    vector<int> kSortedArr(int arr[], int n, int k){

        priority_queue<int, vector<int>, greater<int> > minHeap;

        vector<int> ans;    //sorted array to be returned as answer

        //initialize the minHeap with first k+1 elements
        for(int idx=0; idx<=k; idx++){
    
            minHeap.push(arr[idx]);
        }

        //insert first k elements in ans array as sorted and next elements of array(startig from k+1th index in minHeap)
        for(int idx=k+1; idx<n; idx++){
                ans.push_back( minHeap.top() );
                minHeap.pop();       
                minHeap.push(arr[k+1]); 
                

        }


        //now simply pop rest elements of array starting from k+1th index
        while(!minHeap.empty()){
            ans.push_back( minHeap.top());
            minHeap.pop();
        }

        return ans;


    }





int main(){
    int n= 7;


    int arr[] = {2, 6, 3, 12, 56, 8};
    int k=3;
    
    vector<int> ans = kSortedArr(arr, n, k);

    for(int it =0; it<n;  it++){
        cout<< ans[it]<<" ";
    }

    return 0;
}