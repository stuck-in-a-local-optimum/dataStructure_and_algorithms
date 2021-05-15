

class Solution {
    
    public:
            void markCurrIsland(vector<vector<char> > &grid, int x, int y, int r, int c){
                
                if(x<0 || x>=r || y<0 || y>=0 || grid[x][y]!=1){
                    return ;
                }
                
                grid[x][y] = '2';
                
                markCurrIsland(grid, x-1, y, r, c);
                markCurrIsland(grid, x, y-1, r, c);
                markCurrIsland(grid, x+1, y, r, c);
                markCurrIsland(grid, x, y+1, r, c);
                
            }
    
    
    
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int totalRows = grid.size();
        if(totalRows==0){
            return 0;
        }
        int totalCols = grid[0].size();
        
        int noOfIslands= 0;
        
        for(int row=0; row<totalRows; row++){
            for(int col=0; col<totalCols; col++){
                if(grid[row][col]=='1'){
                    markCurrIsland(grid, row, col, totalRows, totalCols);
                    noOfIslands+=1;
                }
            }
        }
        return noOfIslands;
        
    }
};