import java.util.*;

class Edge{
    int u;
    int v;
    int wt;
    public Edge(int u, int v, int wt){
        this.u = u;
        this.v = v;
        this.wt = wt;
    }
}

class MyComparator implements Comparator<Edge>{
    @Override
    public int compare(Edge e1, Edge e2){
        if(e1.wt > e2.wt){
            return 1;
        }
        if(e1.wt<e2.wt){
            return -1;
        }
        return 0;
    }
}


public class KrushkalAlgo {

        
         public static void main(String args[])
    {
        int n = 5;
        ArrayList<Edge> adj = new ArrayList<>();
		
			
		adj.add(new Edge(0, 1, 2));
		adj.add(new Edge(0, 3, 6));
		adj.add(new Edge(1, 3, 8));
		adj.add(new Edge(1, 2, 3));
		adj.add(new Edge(1, 4, 5));
		adj.add(new Edge(2, 4, 7));

	
		Main obj = new Main(); 
		obj.kruskalAlgo(adj, n);
		
    }
     
    
    
    
    
    private int findPar(int u, int parent[]){
        if(u==parent[u]){ //if reached the ultimate parent of the component
            return u;
        }
        
        
        return parent[u] = findPar(parent[u], parent);  //path compression
    }
    
    private void union(int u, int v, int[] parent, int[] rank){
        
        int uParent = findPar(u, parent);   //ultimate parent of u
        int vParent = findPar(v, parent);  //ultimate parent of v
        
        
        //union by rank
        //if diff ranks then  join the one having smaller rank
        //to the one having larger rank
        if(rank[uParent] > rank[vParent]){
            parent[vParent] = uParent;
        }
        else if(rank[uParent] < rank[vParent]){
            parent[uParent] = vParent;
        }
        
        else{
            //if same rank for both the component's parent
            //then join any one to other
            parent[vParent] = uParent;
            rank[uParent]++; //increment the rank!!
        }
        
        
    }
    
    
    public void kruskalAlgo(ArrayList<Edge> edgeList, int n){
        
        //first of all, sort the edge list
        Collections.sort(edgeList, new MyComparator());
        
        
        //parent[] and rank[] array
        int[] parent = new int[n];
        int[] rank = new int[n];
        
        //initialization
        for(int i=0; i<n; i++){
            parent[i] = i;  //initally each node is a seperate component in itself
            rank[i]=0;  //initially rank is 0
        }
        
        int costMst = 0;
        ArrayList<Edge> mst = new ArrayList<>(); //to store edges of mst
        
        for(Edge edge : edgeList){
            int u = edge.u;
            int v = edge.v;
            int wt = edge.wt;
            
            //if u and v are not in same components then
            //include the edge in the mst and join them
            if(findPar(u, parent) != findPar(v, parent)){
                
                mst.add(edge);
                costMst+=wt;
                
                //union the two components
                union(u, v, parent, rank);
                
            }
        }
        
        System.out.println("MST cost: "+ costMst);
        
        //printing the mst
        for(Edge edge : mst){
            System.out.println(edge.u +"-"+ edge.v);
        }
        
        
    }
    
    
    
    
    
    
}
