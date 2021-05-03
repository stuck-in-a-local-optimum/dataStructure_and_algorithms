#include <iostream>
using namespace std;


//BINARY SEARCH
//Condition: ARRAY MUST BE SORTED ALREADY!


int binarySearch(int arr[], int key, int n){
    int l=0;
    int h=n;
        while(l<=h){
            
            int mid = (l+h)/2;
            if(arr[mid]==key){
                return mid;
            }
            else if(arr[mid]>key){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
}
int findMatch(int arr[], int n){
    int l=0;
    int r = n-1;
    while(l<=r){
        int mid = (l+r)/2;

        if(arr[mid]==mid){
            return mid;
        }
        else if(arr[mid]<mid){
            l=mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}
int temp(int arr[]){
    if(arr[0]==0){
        return 0;
    }
    
    return -1;
}
        

int main(){
    int n,key;

    cout<<"Enter value of n"<<endl;
    cin>>n;
        int arr[n];

    cout<<"Enter elements of the array space seperated"<<endl;
    

    for(int index=0; index<n; index++){
        cin>>arr[index];
    }
    cout<<"Enter key to search in array"<<endl;
    cin>>key;
    cout<<binarySearch(arr, key, n)<<endl;

    //cout<<findMatch(arr, n);
    cout<<temp(arr);

}