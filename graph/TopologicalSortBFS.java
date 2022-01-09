    

import java.util.*;
import java.io.*;
import java.lang.*;
public class TopologicalSortBFS {
   
    
    
 
    //Function to return list containing vertices in Topological order.
    
    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) 
    {
        
        int[] inDeg = new int[V];
        for(int node=0; node<V; node++){
            for(Integer nbr : adj.get(node)){
                inDeg[nbr]++;
            }
        }
        
        Queue<Integer> myQ = new LinkedList<>();
        
        //inserting nodes in myQ which have inDeg=0
        for(int node=0; node<V; node++){
            if(inDeg[node]==0){
                myQ.add(node);
            }
            
        }
        
        int[] ans  = new int[V];
        
        int idx=0;
        
        while(myQ.size()!=0){
            int curr = myQ.remove();
            ans[idx] = curr;
              idx++;
            
            for(Integer nbr : adj.get(curr)){
                inDeg[nbr]--;
                
                
                //if the inDeg become zero add it to the queue
                if(inDeg[nbr]==0){
                myQ.add(nbr);
            }
            }
        }
        
        return ans;
        
    }
}
