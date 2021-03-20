#include <iostream>
using namespace std;

                //CUMMULATIVE SUM APPROACH
                //make a array of cumulative sum and print the sum
                /*
                Given arr = {-1, 4, 7, 2}
                cummArr = {-1, 3, 10, 12}
                max =   cummArr[3]-cummArr[0]



                */

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int cummArr[n+1];
    cummArr[0] = 0;

    //make array for cummulative sum
    for(int i=1; i<=n; i++){
        cummArr[i] = cummArr[i-1]+ arr[i];
    }
    int maxSum = INT_MIN;


    for(int endIndex = 1; endIndex<n; endIndex++){
        int tempSum = 0;

        for(int startIndex=0; startIndex<endIndex; startIndex++){
            tempSum = cummArr[endIndex]-cummArr[startIndex];
            maxSum = max(tempSum, maxSum);


        }

    }
    cout<<maxSum<<endl;


    //we can do it in O(n) using KADANE's algorithm
    int maxS=INT_MIN;
    int curr = 0;

    for(int i=0; i<n; i++){
        curr+=arr[i];
        if(curr<0){
            curr=0;
        }
        maxS = max(maxS, curr);

    }

    cout<<"using Kadane's algo"<<endl;
    


    cout<<maxS<<endl;
    return 0;


    


}


