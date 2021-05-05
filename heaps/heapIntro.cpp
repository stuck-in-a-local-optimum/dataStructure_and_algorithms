#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//COMPILE USING: g++ -std=c++11 heapIntro.cpp -o t


    void maxHeapify(vector<int> &arr, int i){

      int n = arr.size();
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
            maxHeapify( arr, maxIdx);

        }   

    }


      void minHeapify(vector<int> &arr, int i){
      int n = arr.size();
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
            minHeapify( arr, minIdx);

        } 
      }  

    
    void buildHeap(vector<int> &arr, bool ismaxHeap){
                        int n = arr.size();
        int startIdx = n/2 -1;
        for(int i= startIdx; i>=0; i--){
            if(ismaxHeap){
            maxHeapify(arr,0);
        }
        else{
            minHeapify(arr,0);
        }
        }

    }

    void displayHeap(vector<int> &heap){
        int n = heap.size();

        for(int i=0; i<n; i++){
            cout<<heap[i]<<" ";
        }
    }


            // void heapSort(vector<int> &arr, bool isMaxHeap){
            //     int n = arr.size();

            //     buildHeap(arr, isMaxHeap);

            //     for(int i=n-1; i>=1; i--){
            //         swap( arr[0] , arr[i]);
            //         if(isMaxHeap){
            //         maxHeapify(arr, 0);
            //     }
            //     else{
            //         minHeapify(arr, 0);
            //     }

                
            // }
            // }


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

    vector<int> arr1{ 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    vector<int> arr2{ 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

    buildHeap(arr1, true);

    displayHeap(arr1);

    cout<<endl;
    buildHeap(arr2, false);

    displayHeap(arr2);
    cout<<endl;

        

    return 0;
}