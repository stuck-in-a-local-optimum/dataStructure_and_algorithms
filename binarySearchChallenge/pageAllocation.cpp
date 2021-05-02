#include <iostream>
using namespace std;

/*
 n - no. of pages in n different books (in ascending order)
 m - no. of students

 ALL the books have to be divided among m students, consecutively.
 Allocate the pages in such a way that maximum pages allocated 
 to a student is minimum.

 e.g pages = [20, 34, 67, 90]
 students, m= 2

 possible allocation:
    a) [20] [34, 67, 90] --> 191
    b) [12, 34] [67, 90] --> 157
    c) [12, 34], 67] [90]--> 113

    so here c) is the optimal answer 'cause minimum value of maximum allocated pages to
    is 113
*/

/*
STRATEGY

Apply binary search for minimum & maximum possible values of 'max' pages

check the feasibility of this chosen value

---checking feasibility---
Assign pages to each student in a sequential manner, while
the current no. of allocate pages don't exceed the min value set by binary search.

if during allocation, the no. of students don't exceed the limit of 'm'
then the solution is feasible otherwise it isn't.

*/



bool  isFeasible(int arr[], int n, int m, int settedMinValue){
    int studentsReq = 1; //start with one studnet and keep assigning him/her books till reach the settedMinValue
    int currSum=0;

    for(int book=0; book<n; book++){
         if(arr[book] > settedMinValue){
             return false;   //not possible for this setted value
         }

         if( arr[book]+currSum > settedMinValue){ //check do we need new student?
             studentsReq++;    //start allocating to some other student
             currSum = arr[book];

                    if(studentsReq>m){  //keep allocating to new students, if exceed then return false
                        return false;
                    }
         }
         else{  //we not need new student then
             currSum+=arr[book];
             
         }


    }

    return true;

    
}

int allocateMinimumPages(int arr[], int n, int m){

    if(n<m){
        return -1;   //no possible solution, can't allocate n books to m students when m>n
    }

    int sum=0; int ans=INT_MAX;   //initializing

    for(int book=0; book<n; book++ ){
        sum+=arr[book];
    }

    
    int start = 0;  //min possible pages assign to a student is 0
    int end = sum;  //max possible pages assign to a student is sum of pages all books

        while(start< end){
             int mid = (start+end)/2;

             if(isFeasible(arr, n, m, mid)){
                 //then try reducing the minimum value (hence the range) and look for better solution
                 ans = min(ans, mid);
                end = mid-1;    //look for better solution in left half


             }
             else{
                 start = mid+1;
             }


        }


        return ans;
        


}









int main(){

    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;

    cout<<"The minimum no. of pages : "<<allocateMinimumPages(arr,n, m)<<endl;

    return 0;


}