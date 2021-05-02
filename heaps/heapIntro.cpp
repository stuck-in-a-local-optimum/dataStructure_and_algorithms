#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;




int main(){

    //HEAP STL

    priority_queue< int,  vector<int> > pq;   //default one is maxHeap
    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout<< pq.top()<<endl;
    pq.pop();

        cout<< pq.top()<<endl;

// minHeap
    priority_queue< int, vector<int>, greater<int> > pqMin;
    pqMin.push(2);
    pqMin.push(1);
    pqMin.push(3);

    cout<<endl;

    cout<< pqMin.top() <<endl;
    pqMin.pop();
    cout<< pqMin.top()<<endl;
        

    return 0;
}