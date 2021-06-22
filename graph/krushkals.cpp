#include <iostream>
#include <vector>

        /* -------ALGORITHM-------
            1. sort all edges in non-decreasing order of wt.
            2. i) pick the smallest edge
                ii) check if adding the edge forms CYCLE
                iii) if no cycle is formed then include that edge in mst else exclude the edge

                iv) repeat step (2) unless (v-1) edges are included
        */
using namespace std;

struct node{
    int parent;
    int rank;
};

struct Edge{
    int src;
    int dst;
    int wt;
};

//global variables
vector<node> parentArr;
vector<Edge> mst;

int findSet(int v){
    if(parentArr[v].parent==-1){
        return v;
    }
    return parentArr[v].parent = findSet(parentArr[v].parent);   //path compression

}

void unionSet(int fromP, int toP){
    //UNION by rank
    if(parentArr[fromP].rank > parentArr[toP].rank){
        parentArr[toP].parent = fromP;
    }
    else if(parentArr[toP].rank < parentArr[toP].rank){
        parentArr[fromP].parent = toP;

    }
    else{

        //Both have same rank and so anyone can be made as parent
        parentArr[fromP].parent = toP;
        parentArr[toP].rank+=1;   //increase rank of parent by 1

    }
}


bool myComparator( Edge e1, Edge e2){
    return e1.wt < e2.wt;
}

void printEgeList(vector<Edge> &edgeList){
    
    for(auto p : edgeList){
        cout<<"src: "<<p.src<<" dst: "<<p.dst<<" wt:"<<p.wt<<"\n";
        cout<<"==================================================\n";
    }
}

void kruskals(vector<Edge> &edgeList, int V, int E){
    int i=0; int j=0;
    // cout<<"Edge list before sorting\n";
    // printEgeList(edgeList);
    sort(edgeList.begin(), edgeList.end(), myComparator );
    // cout<<"Edge list after sorting\n";
    // printEgeList(edgeList);


    int i=0; int j=0;
    while( i< V-1 && j<E){  //mst will have V-1 vertices and  E edges (all edges)
        int fromP = findSet( edgeList[j].src);
        int toP = findSet( edgeList[j].dst);

        if( fromP == toP){ //if both are already in same set then adding new adge b/w them will make a cycle in mst
            j++;    //which is undesired, so skip
            continue;
        }

        //otherwise join the two src to dst and add the edge to the mst
        unionSet(fromP, toP);
        mst.push_back( edgeList[j]);
        i++;

        
    }

    
}

//Display the formed MST

void printMST(vector <Edge> &mst){
    cout<<"MST formed is\n";
    for( auto p: mst){
        cout<<"src: "<< p.src<<" dst:"<<p.dst<<" wt:"<<p.wt<<"\n";
    }
}





int main(){


    int E; //no. of edges
    int V;  //no. of vetices
    cin>>E>>V;

    parentArr.resize(V); //mark all nodes as independent susbsets with only 1 element
    //initializing the parentArr

    for(int i=0; i<V; i++){
        parentArr[i].parent = -1;
        parentArr[i].rank = 0;
    }

    vector<Edge> edgeList;
    Edge temp;
    for( int i=0; i<E; i++){
        int from, to, wt;
    cin>>from>>to>>wt;
    temp.src = from;
    temp.dst = to;
    temp.wt = wt;
    edgeList.push_back(temp);
    }

    kruskals(edgeList, V, E);
    printMST(mst);




    return 0;
}


//TIME COMPLEXITY: O(ElogE + ElogV)
//ElogE for sorting E edges in edge_list
//ElogV for applying FIND & UNION operations on E edges having V vertices