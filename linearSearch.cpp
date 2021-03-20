#include <iostream>
using namespace  std;


int main(){

    int n;
    cout<<"Enter value of n"<<endl;
    cin>>n;
    cout<<"Enter n elements of the array"<<endl;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];

    }

    cout<<"Enter the key"<<endl;
    int key;
    cin>>key;
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            cout<<"key is at index "<<i<<endl;
            break;
        }
    }
}