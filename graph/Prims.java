package graph;
import java.util.*;

public  class Prims{

    public static void main(String[] args){
       int v=6;

       int[][] graph = { {0, 4, 6, 0, 0, 0},
       {4, 0, 6, 3, 4, 0},
       {6, 6, 0, 1, 8, 0},
       {0, 3, 1, 0, 2, 3},
       {0, 4, 8, 2, 0, 7},
       {0, 0, 0, 3, 7, 0} };

       Prims.primsForMst(graph, v);





    }

    public static int selectMinVertex(int[] values, boolean[] included, int v){
        int minimum = Integer.MAX_VALUE;
        int vertex = -1;

        for(int i=0; i<v; i++){
            if(included[i]==false && values[i]<minimum){
                vertex = i;
                minimum = values[i];
            }
        }


        return vertex;

    }

 public static void primsForMst(int graph[][], int v){
     boolean[] visited = new boolean[v];  //included vtx in mst
     int[] lableValues = new int[v];   //to store label value of each node
     int[] parent = new int[v];    //to remember edges included in mst

     //initializing arrays
     Arrays.fill(visited, false);
     Arrays.fill(lableValues, Integer.MAX_VALUE);

     lableValues[0] = 0;  //start with 0th node
     parent[0] = -1;   //0th node have no parent

     

     //form mst which will have (v-1) edges
     for(int e=0; e<v-1; e++){


        int u = selectMinVertex(lableValues, visited, v);
        visited[u] = true;



        //relax the adjacent vertices (not yet included in mst)
        for(int vtx = 0; vtx<v ; vtx++){
            /* CONSTRAINTS TO RELAX:-
                1. edge should be present from u to vtx
                2. vtx should not be included in mst
                3. edge wt should be smaller than the current edge weight
            */
            if(graph[u][vtx]!=0 && visited[vtx]==false && graph[u][vtx] < lableValues[vtx]){
                parent[vtx] = u;
                lableValues[vtx] = graph[u][vtx];
            }

        }
        

     }

     //print the mst
     
     for(int i=1; i<v; i++){
         System.out.println(String.format("u -> v: %d -> %d wt =  %d", parent[i], i, graph[parent[i]][i]));
     }

 }
}

