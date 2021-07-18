#include <iostream>
#include <math.h>
using namespace std;

//TWO POINTER APPROACH!
int main(){
    int n, s;
    cin>>n;
    cin>>s;
    int arr[n];

    int i=0; int j=0;
    int start= -1;
    int end = -1;
    int currSum=0;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    while( j<n && currSum+arr[j]<=s){
        currSum+=arr[j];
        j++;

    }

    if(currSum==s){
        cout<<i+1<<" "<<j;
        return 0;
    }

    while(j<n){
        currSum+=arr[j];

        while(currSum>s){
            currSum-=arr[i];
            i++;
        }

        if(s==currSum){
            start = i+1;
            end = j+1;  //because of 1 based indexing
            break;
        }
        j++;

    }

    
    cout<<start<<" "<<end<<endl;

}