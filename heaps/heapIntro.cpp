#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;


    void maxHeapify(int arr[], int n, int i){
        int lChild = 2*i+1;
        int rChild = 2*i+2;

        int maxIdx = INT_MIN;
        if(lChild< n && arr[lChild] > arr[i]){
            maxIdx = lChild;
        }
        else{
            maxIdx = i;
        }

        if( rChild< n && arr[rChild]> arr[maxIdx]){
            maxIdx = rChild;
        }

        if( maxIdx !=i){
            swap( arr[i], arr[maxIdx]);
            maxHeapify( arr, n, maxIdx);

        }   

    }


      void minHeapify(int arr[],int n, int i){
        int lChild = 2*i+1;
        int rChild = 2*i+2;

        int minIdx = INT_MAX;
        if(lChild< n && arr[lChild] < arr[i]){
            minIdx = lChild;
        }
        else{
            minIdx = i;
        }

        if( rChild< n && arr[rChild] <arr[minIdx]){
            minIdx = rChild;
        }

        if( minIdx !=i){
            swap( arr[i], arr[minIdx]);
            minHeapify( arr, n, minIdx);

        } 
      }  

    
    void buildHeap(int arr[], int n, bool ismaxHeap){
        int startIdx = n/2 -1;
        for(int i= startIdx; i>=0; i--){
            if(ismaxHeap){
            maxHeapify(arr,n, i);
        }
        else{
            minHeapify(arr, n,i);
        }
        }

    }

    void displayHeap(int heap[], int n){
        for(int i=0; i<n; i++){
            cout<<heap[i]<<" ";
        }
    }









int main(){

    //HEAP STL

    // priority_queue< int,  vector<int> > pq;   //default one is maxHeap
    // pq.push(2);
    // pq.push(3);
    // pq.push(1);

    // cout<< pq.top()<<endl;
    // pq.pop();

    //     cout<< pq.top()<<endl;

// minHeap
    // priority_queue< int, vector<int>, greater<int> > pqMin;
    // pqMin.push(2);
    // pqMin.push(1);
    // pqMin.push(3);

    // cout<<endl;

    // cout<< pqMin.top() <<endl;
    // pqMin.pop();
    // cout<< pqMin.top()<<endl;

    int arr1[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
        int arr2[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

    buildHeap(arr1,11,  true);

    displayHeap(arr1, 11);

    cout<<endl;
    buildHeap(arr2,11,  false);

    displayHeap(arr2, 11);

        

    return 0;
}