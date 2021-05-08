// #include <iostream>
// #include <queue>
// using namespace std;

//                 //---------************(currently giving wrong output)-***********--------------

//                 /*-----MEDIAN OF RUNNING STREAM --------
//                     Numbers are coming and we have to tell the median after
//                     each input.

//                     median: if total numbers are odd the middle element is the median else 
//                             avg of two middle elements is the median.

//                     e.g 10, 15, 21, 30, 18, 19  these numbers are to be streamed one by one

//                     After 4rth input (30)
//                         current stream = 10, 15, 21, 30  (even length)
//                         median = (15+21)/2 = 18
                
//                 */


//                /*--------------APPROACH----------------
//                     1) keep one maxHeap and one minHeap
//                     2) Partition the array in two parts
//                     3) If 'sizes of maxHeap & minHeap not equal then
//                         pop and output the top of larger size heap
//                         else
//                             output the avg of top of both heaps

//                */

//     priority_queue<int , vector<int>, greater<int> > minHeap;
//     priority_queue<int, vector<int> > maxHeap;


//     void insert(int x){

//         if(minHeap.size() == maxHeap.size()){
//             if(maxHeap.size()==0){
//                 maxHeap.push(x);
//                 return;
//             }
            
//             //else
//             if( x< maxHeap.top()){
//                 maxHeap.push(x);
//             }
//             else{
//                 minHeap.push(x);
//             }
//         }

//         else{
//             //two cases

//             //case1:
//             if( maxHeap.size() > minHeap.size()){

//             if( x>= maxHeap.top()){
//                 minHeap.push(x);
//             }
//             else{
//                 int temp = maxHeap.top();
//                 maxHeap.pop();
//                 minHeap.push(temp);
//                 maxHeap.push(x);
//             }

//         }
//         else{
//             if( x>= minHeap.top()){
//                 maxHeap.push(x);
//             }
//             else{
//                 int temp = minHeap.top();
//                 minHeap.pop();
//                 maxHeap.push(temp);
//                 minHeap.push(x);
//             }
//         }
         
//     }
//     }



//     double findMedian(){
//         if( minHeap.size() == maxHeap.size()){
//             return ( minHeap.top() + maxHeap.top())/2;
//         }
//         else if( maxHeap.size() > minHeap.size()){
//             return maxHeap.top();
        
//         }

//         else{
//             return minHeap.top();
//         }
//     }

// int main(){
//         insert(10);
//         cout<<findMedian()<<endl;
//         insert(15);
//         cout<<findMedian()<<endl;
//         insert(21);
//         cout<<findMedian()<<endl;
//         insert(30);
//         cout<<findMedian()<<endl;
//         insert(18);
//         cout<<findMedian()<<endl;
//         insert(19);
//         cout<<findMedian()<<endl;

//     return 0;
// }