#include <iostream>
#include <vector>
#include <queue>
using namespace std;


            /*---------BIPARTITE GRAPH (aka GRAPH COLORING PROBLEM)----------------
            following three statements are equivalent, if one is true then other two also true
                1) Its vertices can be divided into two disjoint and independent
                sets U and V such that every edge connects a vertex in U to one in V.

                2) The graph does not contain any odd-length cycles
                3) The graph is 2-colorable.
            */

           /*-----ALGO TO FIND A GRAPH IS BIPARTITE OR NOT-----

            1) Traverse the graph
            2) if current node is of red color, paint its neighbour as blue.

            If we are able to color the graph successfully, then the graph is bipartite!
        
           */


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


            //this function will color the whole graph starting coloring with node 'u' with color 'clr'
           bool color(vector<int> g[], int n, int node, vector<int> colorArr){

    colorArr[node] = 1;  // let's colr the first node with 1

    queue<int> myQ;
    myQ.push(node);


    while (!myQ.empty()) {
        int curr =  myQ.front();
        myQ.pop();

        //now work on nbrs of curr

        vector<int> :: iterator nbr;
        for(nbr = g[curr].begin(); nbr!=g[curr].end(); nbr++){

            if(colorArr[*nbr] == colorArr[curr]){
                return false;
            }

            if(colorArr[*nbr]==-1){  //if nbr is uncolored  or unvisited node
            colorArr[*nbr] = colorArr[curr] xor 1;  //color the nbr with opposite colr
            myQ.push(*nbr);
            }
        }  
    }

    return true;  //all graphs are successsfully colored without any ambiguity then return true
    
}


bool isBipartite(vector<int> g[], int n){
    vector<int> colorArr(n+1, -1);

    for(int node=1; node<=n; node++){
        if(colorArr[node]==-1){ //if node is uncolored
            if(color(g, n, node, colorArr)){
                return true;
            }

        }
    }
    return false;
    
}



int main(){

    int n=4;
    vector<int> g[n+1];

    addEdge(g, 1, 2, false);
    addEdge(g, 2, 3, false);
    addEdge(g, 3, 4, false);
    addEdge(g, 4, 1, false);
    addEdge(g, 4, 2, false);

    cout<<isBipartite(g, n)<<endl;



    return 0;
}