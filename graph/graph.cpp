#include <iostream>
#include <vector>
#include <iterator>
#include <queue>

using namespace std;


void dfs(int start, vector<int> g[], bool isVisited[]){
    isVisited[start] = true;   //mark the curr node visited
    cout<<start<<" ";           //output the current node

    for(int i=0; i<g[start].size(); i++){  //call dfs for each neighbour of node current node
    if(isVisited[g[start][i]]==false){
        dfs( g[start][i], g, isVisited);   //we are using recursion & since recurison uses stack, so we are implicitely using stack
    }
     
}
}

void bfs(int start, int n, vector<int> g[]){
     bool isVisited[n+1];
    memset( isVisited, false, sizeof(isVisited));
    queue<int> myQ;
    myQ.push(start);

    isVisited[start] = true;

    while(!myQ.empty()){ 
        int curr = myQ.front();
        myQ.pop();
        cout<<curr<<" ";
        
        vector<int> :: iterator it;
        for(it = g[curr].begin(); it!=g[curr].end(); it++){
            if(isVisited[*it]==false){
                myQ.push(*it);
                isVisited[*it] = true;
            }
        }
    }
    

}


void addEdge(vector<int> g[], int u, int v, bool isDirected){
    g[u].push_back(v);

    if(!isDirected){
    g[v].push_back(u);
}
}

//-------CYCLE DETECTION IN DIRECTED GRAPH--------

bool isCyclicUtility(vector<int> g[], int n, int node, vector<int> isvisited){
    if(isvisited[node]==2){  //if the current node was already is in processing then cycle!
        return true;

    }

    isvisited[node] =2; //set the node in processing

    vector<int> :: iterator nbr;
    for(nbr = g[node].begin(); nbr!=g[node].end(); nbr++){
        if(isvisited[*nbr]!=1){
            if(isCyclicUtility( g, n, *nbr, isvisited)){
                return true;

            }
        }
    }

    isvisited[node] = 1; //after visiged all its nbrs, node is processed and cycle found
    return false;  
}

bool isCyclicDir(vector<int> g[], int n){
    //isVisited[i] ==0, means node 'i' is not unvisited
    //isVisited[i] ==2, means node 'i' is in processing (workin on its nbrs)
    //isVisited[i] == 1, means node 'i' has been processed
    
    vector<int> isVisited(n+1, 0);    //initially all nodes are unvisited

    for(int node=1; node<=n; node++){

        if(isVisited[node]==0){
            if(isCyclicUtility(g, n, node, isVisited)){
                return true;

            }

        }
        return false;

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


//--------CONNECTED COMPONENTS-----------
//--ALGORITHM--
/*
    1) visit the nodes in a depth-first fashion
    2) if the node is not visited, visit that node and its neighbour
    recursively

    Each time a unvisited node is found, a new componenent will be found.

*/

int getComponentSize( vector<int> g[], vector<bool> isVisited, int src){

    int size=1; //initialize each new found componenet  must have size=1

    if(isVisited[src]){
        return 0;
    }

    vector<int> :: iterator it;
    for( it = g[src].begin(); it!=g[src].end();  it++){

        if(!isVisited[*it]){
            size+=getComponentSize(g, isVisited, *it);
        }

    }


return size;
}  




int noOfConnComponents(vector<int> g[], vector<bool> isVisited, int n){

    vector<int> components;
    
    vector<bool> isVisited(n=1, false);

    for(int node=1; node<=n; node++){
        if(!isVisited[node]){  //new component found
        components.push_back( getComponentSize(g, isVisited, node));

        }
    }


}








    





int main(){

        cout<<"enter values of n"<<endl;
        int n;   //no. of vertices 
        cin>>n;

        vector<int> g[n+1];  //adjacency list, vector of vector

        bool isVisited1[n+1];

        memset( isVisited1, false, sizeof(isVisited1)); //set all valus false inititially

        addEdge(g, 1, 2, false);
        addEdge(g, 1, 3, false);
       addEdge(g, 2, 4, false);
        addEdge(g, 2, 5, false);
        addEdge(g, 2, 6, false);
        addEdge(g, 2, 7, false);
        addEdge(g, 7, 3, false);

        cout<<"Graph: "<<endl;
        printGraph(g, n);

        //cout<<"dfs output: "<<endl;

        dfs(1, g, isVisited1);
        cout<<endl;

        bfs(1, n,  g);
        cout<<endl;



    
        

    





    return 0;
}