#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int min= INT_MAX;

    int arr[n];

    for(int i=0 ; i<n; i++){
        cin>>arr[i];
    }
    const int N = 1e6+2 ;
    int arr2[N];


    for(int i=0 ; i<n; i++){
        arr2[i] = -1;
        
    } 

    for(int i= 0; i< n; i++){
        if(arr2[arr[i]]!=-1 && min>arr2[arr[i]]){
            min = arr2[arr[i]];
        }
        else{
            arr2[arr[i]] =i;
        }

    }

    cout<<min;





}