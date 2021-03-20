#include <iostream>
using namespace std;

//ALGO--> Insert an element from unsorted array to its correct postionin sorted array
 //assume first element as sorted


    void insertionSort(int arr[], int n){

        for(int i=1; i<n; i++){
            for(int j=i; j>=1; j--){
                if(arr[j]<arr[j-1]){
                    int temp = arr[j];
                     arr[j]=arr[j-1];
                     arr[j-1]=temp;
                }
                else{
                    break;
                }
            }

        }
        for(int i=0; i<n; i++){
        cout<<arr[i]<<", ";
    }

    }



int main(){
int n;
             cout<<"Enter value of n"<<endl;
    cin>>n;
        int arr[n];

    cout<<"Enter elements of the array space seperated"<<endl;
    

    for(int index=0; index<n; index++){
        cin>>arr[index];
    }
   
    insertionSort(arr,n);



return 0;
}