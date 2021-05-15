#include <iostream>
#include <vector>
#include <queue>

using namespace std;




void addEdge(vector<int> g[], int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
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

bool isCyclicUtility( int src, vector<int> g[], vector<bool> isVisited, int parent){

    isVisited[src] = true;

    //work on neighbours of src
    vector<int> :: iterator it;   //iterator to iterate to all nbrs of src
    for(it = g[src].begin(); it!=g[src].end(); it++){
        if( *it!=src ){
            if(isVisited[*it]){  //if visited then cycle present

                return true;
            }
            if(!isVisited[*it] && isCyclicUtility(*it, g, isVisited, src)){
                return true;
            }
        }

    }
    return false;

}

//cycle detection in undirected graph
void isCyclic( vector<int> g[], int n){

        //isVisited arr
        vector<bool> isVisited(n+1, false);  //instantiated with false
        
        bool flag = false;
        //work for each node
        for(int node = 1; node<=n; node++){
            if( !isVisited[node] && isCyclicUtility( node, g, isVisited, 0)){
                flag = true;

            }

        }
        if(flag){
            cout<<"cycle is present"<<endl;
        }
        else{
            cout<<"cycle is not present"<<endl;
        }

}











int main(){

    int n=4;
     vector<int> g[n+1];

     vector<bool> isVisited(n, false);

     addEdge(g, 1, 2);
     addEdge(g, 2, 3);
     addEdge(g, 3, 1);

     isCyclic(g, n);



    return 0;
}