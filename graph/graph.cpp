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