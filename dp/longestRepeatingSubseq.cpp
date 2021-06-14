
#include <iostream>
using namespace std;
/*---------important observation
    If we observe, finding LRS is same as finding LCS only difference is, here we
    have contraint that we can't choose char in which have same index

-----------*/
    


int LRS(string A) {
    int n = A.size();
    
    int dpTable[n+1][n+1];
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dpTable[i][j]=0;
            }
            else if(A[i-1]==A[j-1] && i!=j){  
                dpTable[i][j] = 1+dpTable[i-1][j-1];
            }
            else{
                    dpTable[i][j] = max(dpTable[i-1][j], dpTable[i][j-1]);
                
            }
        }
    }
    return dpTable[n][n];
}

string findLRS(string s){
        int n = s.size();

        string dpTable[n+1][n+1];

        for(int i=0; i<=n; i++){
            dpTable[i][0] = "";
        }
         for(int i=0; i<=n; i++){
            dpTable[0][i] = "";
        }

         for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==s[j-1]){
                    dpTable[i][j] = dpTable[i-1][j-1]+s[i-1];

                }
                else{
                    dpTable[i][j] = dpTable[i-1][j].size() > dpTable[i][j-1].size()? dpTable[i-1][j]: dpTable[i][j-1];
                    
                }
                
            }
        }
        return dpTable[n][n];
    }
    





int main(){

    cout<<LRS("aabb")<<endl;
    cout<<findLRS("aabb");
}