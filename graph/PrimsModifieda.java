import java.util.*;
public  class PrimsModifieda {
    
    static class Node{
        int vrtx;
        int wt;
        public Node(int v, int w){
            this.vrtx = v;
            this.wt = w;
        }
    }
    
    
    public static void main(String args[]) {
        ArrayList<ArrayList<Node> > adj = new ArrayList<>();
        int n = 5;
        
        //creating a graph
        for(int node=0; node<n; node++){
            adj.add(new ArrayList<>());
        }
        
        adj.get(0).add(new Node(1, 2));
        adj.get(0).add(new Node(3, 6));
        
        adj.get(1).add(new Node(2, 3));	    
        adj.get(1).add(new Node(4, 5));        
        adj.get(1).add(new Node(0, 2));
        adj.get(1).add(new Node(3, 8));
        
        adj.get(2).add(new Node(1, 3));
        adj.get(2).add(new Node(4, 7));
        
        adj.get(3).add(new Node(0, 6));
        adj.get(3).add(new Node(1, 8));
        
        adj.get(4).add(new Node(1, 5));
        adj.get(4).add(new Node(2, 7));
        
        
        
		Prims obj = new Prims();
		obj.primsAlgo(n, adj);
    
    }
    
    public void primsAlgo(int n, ArrayList<ArrayList<Node>> adj){
        
        boolean[] mstSet = new boolean[n];  //will keep track of vertices included in MST
        int[] key = new int[n];   //assign each key value to all vertices, at each iteration the one with min key value will be picked
        int[] parent = new int[n]; //parent array to save structure of MST
        
        //initialization
        for(int node=0; node<n; node++){
            mstSet[node] = false;
            key[node] = Integer.MAX_VALUE;
            parent[node] = -1;
        }
        
        
        //comparator for the priorityQueue
        Comparator<Node> myComparator = (a, b)->{
            return a.wt - b.wt;
        };
        
        PriorityQueue<Node> minHeap = new PriorityQueue<>(myComparator);
        
        key[0]= 0; //set it to 0 so that the node-0 get picked first
        
        minHeap.add(new Node(0, key[0]));
        
        
        for(int i=0; i<n-1; i++){ //for n-1 edges in MST
        
        //search the vertex  'u' with min. key value which has not been included in the mst 
        //(in this modified oversion of algo we are doing it in logn time instead of O(N^2))
     
        
        int u = minHeap.poll().vrtx;
        
        //include the vertex u in the MST
        mstSet[u] = true;
        
        
        //now update the key and parent array for the nbrs of vertex u
        for(Node nbr : adj.get(u)){
            
            if(mstSet[nbr.vrtx]==false && nbr.wt < key[nbr.vrtx]){
                parent[nbr.vrtx]= u;
                key[nbr.vrtx] = nbr.wt;
                minHeap.add(new Node(nbr.vrtx, key[nbr.vrtx]));
            }
        }
        
    
            
        }
        
        //print the mst
        for(int node=0; node<n; node++){
            System.out.println(parent[node]+" - " + node);
        }
        
    }
    
    
    
    
}
