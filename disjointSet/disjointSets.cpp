#include <iostream>
#include <vector>
using namespace std;

//global 'parent array' which array contains parent of each vertex
vector<int> parentArr;


//Find operation, is returns the absolute parent of a given vertex
 int findOperation(int vrtx){
     if(parentArr[vrtx] == -1){   //if it is absolute parent then return it self
         return vrtx;
     }
     return findOperation( parentArr[vrtx]); 
 }

 void unionOperation(int fromP, int toP){
     fromP   = findOperation(fromP);  //getting the absolute parent
     toP = findOperation(toP);

     parentArr[fromP] = toP;   //getting the abosolute parent of toP

 }


 bool isCyclic( vector<pair<int, int> > &edgeList){
     for( auto  p : edgeList){
         int fromP = findOperation( p.first);
         int toP = findOperation( p.second);

         if( fromP == toP){
             return true;
         }

         unionOperation( fromP, toP);
     }

     return false;

 }






int main(){

    int E;   //No. of edges
    int V;   //no. of vertices

        cout<<"enter no. of edges and vertices\n";
    cin>>E>>V;

    parentArr.resize( V, -1);   //marking all the vertices with seperate subsets with one element

    vector<pair<int, int> > edgeList;

        //prepairing the edge list
    for(int i=0; i<E; i++){
        int from, to;
        cin>>from>>to;
        edgeList.push_back( {from, to});
    }

    if(isCyclic(edgeList)){
        cout<<"TRUE\n";
    }
    else{
        cout<<"FALSE\n";
    }



    




    return 0;
}