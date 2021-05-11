#include <iostream>
#include <vector>
#include <queue>
using namespace std;





void addEdge(vector<int> g[], int inDeg[], int u, int v, bool isDirected){
    g[u].push_back(v);
    inDeg[v]++;

    if(!isDirected){
    g[v].push_back(u);
    inDeg[u]++;
}
}

void printGraph(vector<int> g[], int n){
    for(int i=1; i<n+1; i++){
        cout<<i<<" -> ";

        vector<int> :: iterator it;
        for( it = g[i].begin(); it!=g[i].end(); it++){
            cout<<*it<<" ";
   }
        cout<<endl;
    }
}



/*----------------ALGORITHM----------

    while( all the nodes are not visited){
        nodes with zero inDegree can be added to the
        output array.
        All the nodes which are adjacent to terminal
        nodes, gets their inDegree subracted
    }

    //----implementtation using queue
        1) push all the nodes with inDegree=0;
        2) now pop one by one and for each popped node
            work on thier neighbours

*/

void topologicalSort(vector<int> g[], int inDeg[], int n){
    queue<int> myQ;


    //push all the nodes with 0 inDegree in Queue
    for(int i=1; i<=n; i++){
        if(inDeg[i]==0){
            myQ.push(i);
        }
    }


    while(!myQ.empty()){

        //pop one by one
        int temp= myQ.front();
        myQ.pop();

        cout<<temp<<" ";

        vector<int> :: iterator it;

        //work on neighbours
        for(it = g[temp].begin(); it!=g[temp].end(); it++){
            inDeg[*it]--;
            if(inDeg[*it]==0){
                myQ.push(*it);
                 }
            }


    }

}




int main(){

    int n=4;

    vector<int> g[n+1];
    int inDegree[n+1];

    //instantiate inDegree
    for(int i=0; i<=n; i++){
        inDegree[i] = 0;
    }

    addEdge(g, inDegree, 1, 2, true);
    addEdge(g, inDegree, 3, 4, true);
    addEdge(g, inDegree, 2, 3, true);

    

    topologicalSort(g, inDegree, n);











    return 0;
}