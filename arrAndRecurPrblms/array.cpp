#include <iostream>
using namespace std;


int main(){

    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;

    int myArray[n];
        cout<<"Enter n elements of the array"<<endl;


    for(int i=0;i<n; i++){
        cin>>myArray[i];

    }

     for(int i=0;i<n; i++){
        cout<<myArray[i]<<", ";

    }



}