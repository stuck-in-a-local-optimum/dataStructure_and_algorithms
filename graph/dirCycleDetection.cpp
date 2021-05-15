#include <iostream>
#include <vector>
using namespace std;




void addEdge(vector<int> g[], int u, int v, bool isDirected){
    g[u].push_back(v);
    if(isDirected){
    g[v].push_back(u);
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

bool isCyclicUtility(int src, vector<int> g[], vector<bool> isVisited, vector<bool> stackArr){
    stackArr[src] = true;
    
    if(!isVisited[src]){
        isVisited[src] = true;

        vector<int>  :: iterator it;

        for(it = g[src].begin(); it!=g[src].end(); it++){
            if(!isVisited[*it] && isCyclicUtility( *it, g, isVisited, stackArr)){
                return true;
            }

            if(stackArr[*it]){ //if this node is already in stack then return true!
                return true;
            }
        }
    }

        stackArr[src]=false;

        return false;

    }








void isCyclic(vector<int> g[], int n ){

    vector<bool> stackArr(n+1, false);  //arr to store nodes that currently in stack
    vector<bool> isVisited(n+1, false);
    bool flag = false;
    for(int node=1; node<=n; node++){
        if(!isVisited[node] && isCyclicUtility(node, g, isVisited, stackArr)){
            flag = true;

        }
       
    }
     if(flag){
            cout<<"Cycle is present"<<endl;
        }
        else{
            cout<<"Cycle is not present"<<endl;
        }
}




int main(){

    int n=4;
    vector<int> g[n+1];

    addEdge(g,1, 2, true );
    addEdge(g, 2, 3, true);
    addEdge(g, 3, 2, true);

    isCyclic(g, n);



return 0;

}