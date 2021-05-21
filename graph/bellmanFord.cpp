#include <iostream>
#include <vector>
using namespace std;

struct edge{
    int src, dst, wt;

};

int V, E;

void bellmanFord(vector<edge> &edges){
    int parent[V];   //stores shortest path structure
    int costParent[V];   //cost of the node ot parent edge weight
    vector<int> value(V, INT_MAX);    //it keeps the path vlaues of each vertex from source


    //assuming start point as node 0
    parent[0]  = -1;  //start node has no parent
    value[0] = 0;    //start node has value=0 to get picked first

    //include (V-1) edges to cover all V - Vertices
    bool updated;
    for(int i=0 ; i<V-1; i++){
        updated = false;

        //do for each edge
        for(int j=0; j <E; j++){
            int u = edges[j].src;
            int v = edges[j].dst;
            int wt = edges[j].wt;

            if( value[u] != INT_MAX && value[u]+wt < value[v]){
                value[v] =  value[u]+wt;
                parent[v] = u;
                costParent[v] = value[v];
                updated = true;
            }
        }

        if(!updated){
            break;   //no need to check for other vertices,no update possible
        }
    }

    //now check by relaxing once more if we have a negative edge cycle

    for(int j=0; j<E && updated == true; j++){
        int u = edges[j].src;
        int v = edges[j].dst;
        int wt = edges[j].wt;

        if( value[u] !=INT_MAX && value[u]+wt < value[v]){
            cout<<"Graph has -ve edge cycle\n";
            return;
        }
    }

    //print shortest path graph
    for(int i=1; i<V; i++){
        cout<<"u->v: "<<parent[i]<<"->"<<"cost to reach "<<parent[i]<<" from source 0 = "<<value[i]<<"\n";
    }

}



int main(){

    /*--INPUT--
    5 10
0 1 6
0 2 7
1 2 8
1 3 -4
1 4 5
2 3 9
2 4 -3
3 4 7
3 0 7
4 1 -2
    
    
    */
    cin>>V>>E;	//Enter no of Vertices and Edges
	vector<edge> Edges(E);

	//Now input all E edges
	int src,dst,wt;
	for(int i=0;i<E;++i)
	{
		cin>>src>>dst>>wt;
		Edges[i].src = src;
		Edges[i].dst = dst;
		Edges[i].wt = wt;
	}

	bellmanFord(Edges);	


    return 0;
}