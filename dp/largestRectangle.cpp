#include <iostream>
#include <vector>
#include <stack>
using namespace std;
            /*---LARGEST RECTANGLE IN HISTOGRAM, leetcode-84----
                Given an array of integers heights representing the 
                histogram's bar height where the width of each bar is 1, 
                return the area of the largest rectangle in the histogram.
            */


           /*-----------STRATEGY---------
           1) we observed that the largest rectangle always contains atleast 1 bar
            in full , so if we find areas of all largest rectangles for each bar
            being included in maximum rectangle area

            2)so we will take maximum of all the max areas for each bar found

        //-------ALGO-----
            1) we will find the left bar with height less than the curr bar (if not found then left[i]=0 i.e first bar)
            2) similarly we find the right bar with height less than the curr bar (else n-1th bar)
            3) for each bar, max area = (right[i]-left[i]+1)*height[i], we will take max of them
            4) to remember prev smaller element (to find left or right bar for each bar) we use stack, we will maintian elements in increasing order
            with the largest being at the top of the stack.
           */



        int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> left(n);
        vector<int> right(n);
        stack<int> myStack;   //to maintain the increasing order of bars based on height 

        for(int i=0; i<n; i++){
            if(myStack.empty()){
                left[i] = 0;
                myStack.push(i);
            }
            else{
                while(!myStack.empty() &&  heights[myStack.top()] >= heights[i]){ //pop till left smaller height bar found for each bar
                        myStack.pop();

                }
                left[i] = myStack.empty() ? 0 : myStack.top()+1;   //fill appropriate left bar for each bar
                myStack.push(i);   //done with curr bar

            }
        }


        while (!myStack.empty())
        {
            myStack.pop();
        }
        



         for(int i=n-1; i>=0; i--){
            if(myStack.empty()){
                right[i] = n-1;
                myStack.push(i);
            }
            else{
                while(!myStack.empty() && heights[myStack.top()] >= heights[i]){ //pop till left smaller height bar found for each bar
                        myStack.pop();

                }
                right[i] = myStack.empty() ? n-1 : myStack.top()-1;   //fill appropriate left bar for each bar
                myStack.push(i);   //done with curr bar

            }
        }

        int maxArea = 0;


        for(int i=0; i<n; i++){
            maxArea = max(maxArea, heights[i]*(right[i]-left[i]+1));
        }

        return maxArea;



        
        
    }




int main(){

    vector<int> heights;

    heights.push_back(2);
      heights.push_back(1);
        heights.push_back(5);
          heights.push_back(6);
            heights.push_back(2);
              heights.push_back(3);

    cout<<largestRectangleArea(heights)<<"\n";



    return 0;
}