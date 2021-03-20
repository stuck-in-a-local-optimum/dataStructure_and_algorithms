#include <iostream>
using namespace std;


void countSort(int arr[], int n){

    int k = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>k){
            k = arr[i];
        }
    }

int countArr[9];
    for(int i=0; i<9; i++){
        countArr[i]=0;
    }

    for(int i=0; i<n; i++){
        countArr[arr[i]]++;
    }

    for(int i=1; i<k; i++){
        countArr[i] = countArr[i-1];
    }

    int output[n];

    for(int i=n-1; i>=0; i--){
        output[--countArr[arr[i]]] = arr[i];

    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }

}



int main(){
    int arr[] = {1, 3, 2, 3,4, 1, 6, 4, 3};

    countSort(arr, 9);

    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }



    return 0;
}



