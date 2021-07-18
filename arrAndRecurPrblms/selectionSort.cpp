#include <iostream>
using namespace std;
//ALGO: FIND THE MINIMUM ELEMENT UNSORTED ARRAY AND SWAP IT WITH ELEMENT AT BEGINING

void selectionSort(int arr[]){
    int i=0;
    int n= sizeof(arr);

    while(i<n-1){
        int min=arr[i];
        for(int j=i+1; j< n; j++){
            if(arr[j]<arr[i]){
                min=arr[j];
                int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
            }


        }
        

        i++;

    } 
    for(int i=0; i<n;i++){
     cout<<arr[i]<<" ";
}


}


int main(){

int n;
cout<<"Enter value of n"<<endl;
cin>>n;
cout<<"Enter elements of the array comma seperated"<<endl;
int arr[n];
for(int i=0; i<n;i++){
     cin>>arr[i];
}
selectionSort(arr);
return 0;

}
