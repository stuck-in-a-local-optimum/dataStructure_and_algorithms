package graph;

public class FloydWarshallAlgo {

                        //-----FLOYD-WARSHALL for all pairs shortest path between all pair of vertices  (refer to notes if needed)

                //--------ALGORITHM-------------------*/
                    //-> include each vertex-k one by one in calculation of shortest path
                    //-> As soon as we find a shortest path, we update our shortest path value 
                    //-> for vertex-k, D[i][j] = min( D[i][j], D[i][k]+D[k][j] )

    public static void main(String[] args){
        int v= 6;
        int graph[][] = { {0, 1, 4, Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE},
						{Integer.MAX_VALUE, 0, 4, 2, 7, Integer.MAX_VALUE},
						{Integer.MAX_VALUE, Integer.MAX_VALUE, 0, 3, 4, Integer.MAX_VALUE},
						{Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, 0, Integer.MAX_VALUE, 4},
						{Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, 3, 0,Integer.MAX_VALUE},
						{Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, 5, 0} };

                        FloydWarshallAlgo.floydWarshall(graph, v);
	


    }

    public static void floydWarshall(int[][] graph, int v){
        int[][] distanceMatrix = new int[v][v];

        //initially(copy) assign every edges cost
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                distanceMatrix[i][j] =graph[i][j];
            }
        }


        //find all pairs shortest path by trying all possible paths
        for(int k=0; k<v; k++){  //including/excluding vertex-k
            for(int i=0; i<v; i++){  //try for all possible starting position
                for(int j=0; j<v; j++){  //try for all possible ending position
                    if(distanceMatrix[i][k]==Integer.MAX_VALUE || distanceMatrix[k][j]==Integer.MAX_VALUE){     //in these case we will skip (not include vertex-k)
                        continue;   

                    }
                    else if(distanceMatrix[i][k] + distanceMatrix[k][j] < distanceMatrix[i][j]){  //D[i][j] = min( D[i][j], D[i][k]+D[k][j] )
                        distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                    }

                }
            }
        }


        //check for -ve edge weight cycle
        for(int i=0; i<v; i++){
            if(distanceMatrix[i][i]<0){
                System.out.println("Negative edge weight cycle is present\n");
                return;
            }
        }


        //print shortest path graph
        for(int i=1; i<v; i++){
            for(int j=0; j<v; j++){
                System.out.print(i);
                System.out.println(String.format(" to %d distance is %d" , j, distanceMatrix[i][j] ));
                System.out.println("=================================");
            }
        }


    }
    
}
