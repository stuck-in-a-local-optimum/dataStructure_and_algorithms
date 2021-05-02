#include <iostream>
using namespace std;

    /*
            ----PAINTER'S PARTITION PROBLEM------
            n - length of n different boards
            m - painters available

            A painter  paints 1 unit of board in 1 unit of time & 
            each painter will paint consecutive boards. 
            Find the minimum time that will be required to paint to all the boards.

            e.g boards = [10, 20, 30, 40]
                painters, m = 2;


                possible partitions
                    [10] [20, 30, 40]   ---> 90
                    [10, 20] [30, 40]   ---> 70
                    [10, 20, 30] [40]   ---> 60


                    optimal answer = 60
    */


   /*       -------THE STRATEGY-----(same as page allocation problem, refer to its code comment if needed)

        --> Apply binary search for minimum & maximum possible values of 'min' 
        length of boardss to be painted

        --> check feasibility of this chosen value.

        -----CHECKING FEASIBILITY----

        --> Assign boards to each painter in a seqeuential manner, while 
        the current length of assigned boards don't exceed the value set by binary search.

        --> if during allocation, the no. of painters don't exceed the limit of 'm' painters then
                the solution is feasible otherwise it isn't
   */

  bool isFeasible(int boards[], int n, int m, int settedMinValue){
      int paintersReq=1; int currTime=0;

      for(int board=0; board<n; board++){  //sequentially assign boards to painters
          if(boards[board]>settedMinValue){
              return false;
          }

          if(currTime+boards[board]>settedMinValue){  //need new painter
              paintersReq++;   
              currTime = boards[board];

              if(paintersReq>m){  
                  return false;
              }

          }
          else{
              currTime+=boards[board];
          }

          
      }
      return true;

  }


    int paintersPartition(int boards[], int n, int m){

        if(m>n){
            return -1;  //can't
        }

        int totalLength = 0; int ans = INT_MAX;

        for(int board=0; board<n; board++){
            totalLength +=boards[board];
        }

        int start=0;  //minimum time taken is when no boards is assign
        int end=totalLength;  //maximum time if all the boards assign to a single painter

        while( start<end){
            int mid = (start+end)/2;

            if(isFeasible(boards, n, m, mid)){
                ans = min(ans, mid);
                end = mid-1;
            }
            else{
                start= mid+1;
            }
        }

        return ans;

    }







int main(){

    int boards[] = {10, 20, 30, 40};
    int n = 4;
    int m=2;
    cout<<"minimum time to paint boards : "<<paintersPartition(boards, n, m)<<endl;
    return 0;
}