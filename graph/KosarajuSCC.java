package graph;

import java.util.ArrayList;
import java.util.Stack;

                        /*----KOSARAJU ALGORITHM TO FIND ALL THE STRONGLY CONNECTED COMPONENTS of a graph
                        -> SCC: If from any node we can reach every other node in a component of a graph then that component is SCC.
                        -> A single node is always a SCC
                        
                        -------ALGO-------:
                            1) Perform DFS traversal of graph. Push node to stack before returning to any node.
                            2) Find out transpose graph by reversing the edges of original graph.
                            3) Pop nodes one by one from stack and do DFS on modified graph. (keep popping nodes), each successfull DFS
                                gives 1 SCC.
                        
                        
                    
                        */

public  class KosarajuSCC {
    public int v = 8;
    public static ArrayList<ArrayList<Integer> > graph;
    public static  ArrayList<ArrayList<Integer> >  reverseGraph;


    public static void addEdge( ArrayList<ArrayList<Integer> > graph, int u, int v){
        graph.get(u).add(v);

    }



    public static void main(String[] args){
        int v = 8;
        graph = new  ArrayList<ArrayList<Integer> >();

        for(int i=0; i<v; i++){
            graph.add( new ArrayList<Integer>());
        }
        addEdge(graph, 0, 1);
        addEdge(graph, 1, 2);
        addEdge(graph, 2, 0);
        addEdge(graph, 2, 3);
        addEdge(graph, 3, 4);
        addEdge(graph, 4, 5);
        addEdge(graph, 5, 6);
        addEdge(graph, 6, 4);
        addEdge(graph, 6, 7);
       

        findSCCs(v, graph);

        
        


    }
    public static void DFS1(int node, ArrayList<ArrayList<Integer> > graph,  boolean visited[], Stack<Integer> myStack){
        visited[node]= true;

        for(int nbr : graph.get(node)){ //do DFS traversal of the graph and while returning to from a node, push it in the stack
            if(!visited[nbr]){
                DFS1(nbr, graph,  visited, myStack);
            }
        }

        myStack.push(node);   //before returning push the node in the stack
    }

    public static ArrayList<ArrayList<Integer> > reverseGraph(int v, ArrayList<ArrayList<Integer> > graph){
        ArrayList<ArrayList<Integer> > rGraph = new ArrayList<ArrayList<Integer>> ();
        for(int i=0; i<v; i++){
            rGraph.add( new ArrayList<Integer>());
        }

        for(int i=0; i<v; i++){

            for(int nbr: graph.get(i)){
                rGraph.get(nbr).add(i);
            }


        }
        return rGraph;


    }

    public static void DFS2(int node, ArrayList<ArrayList<Integer> > rGraph, boolean visited[]){
        System.out.print(node+" ");          //all the nodes till we find a node already visited are part of a SCC

        visited[node] = true;

        for(int nbr: rGraph.get(node)){
            if(!visited[nbr]){
                DFS2(nbr, rGraph , visited);
            }
        }

    }


        
    

   public static  void findSCCs(int v, ArrayList<ArrayList<Integer> > graph){
       Stack<Integer> myStack = new Stack<>(); //stack to keep account fro which nodes to  manually start exploring next SCC in the transpose graph
       boolean visited[] = new boolean[v];   //keep record of visited nodes while DFS
       for(int i=0; i <v; i++){
           visited[i] = false;
       }

       for(int i=0; i<v; i++){   //do DFS traversal of the graph and while returning to from a node, push it in the stack
           if(!visited[i]){
               DFS1(i, graph, visited, myStack);   
           }
       }


       ArrayList<ArrayList<Integer> > rGraph =  reverseGraph(v, graph);   //transpose graph after reversing all the edges
      


       //reinitialize the each index of visited array to false
       for(int i=0; i<v; i++){
           visited[i] = false;
       }
       System.out.println("Strongly connected components are: \n");

       while(!myStack.empty()){  //keep popping from stack and do DFS from popped node in rGraph, if already visited node found then print all the nodes visited so far as a SCC
           int curr =myStack.pop();
           

           if( visited[curr]==false){
               DFS2(curr, rGraph, visited);
               System.out.print("\n");
           }
       }



    }


    
}
