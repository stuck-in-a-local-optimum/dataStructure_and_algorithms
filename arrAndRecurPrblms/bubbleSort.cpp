#include <iostream>
using namespace std;
//ALGO: Repeatedly swap two adjacent elements if they are in wrong order


void bubbleSort(int arr[]){
    
    int counter=1;
    int n = sizeof(arr);
    while(counter < n){
        for(int i=0; i<n-counter; i++){
            if(arr[i]>arr[i+1]){

                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;

            }

        }
        counter++;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<", ";
    } cout<<endl;

}
int main(){
    int n;
    cout<<"Enter value of n"<<endl;
    cin>>n;

    int arr[n];
    

    cout<<"Enter elements of array space seperated"<<endl;

      for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    bubbleSort(arr);

}