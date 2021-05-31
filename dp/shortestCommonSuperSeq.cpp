

class Solution {
    
    
   string findLCS(string str1, string str2){
        int n1 = str1.size();
        int n2 = str2.size();

        string dpTable[n1+1][n2+1];

        for(int i=0; i<=n1; i++){
            dpTable[i][0] = "";
        }
         for(int i=0; i<=n2; i++){
            dpTable[0][i] = "";
        }

         for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(str1[i-1]== str2[j-1]){
                    dpTable[i][j] = dpTable[i-1][j-1]+str1[i-1];

                }
                else{
                    dpTable[i][j] = dpTable[i-1][j].size() > dpTable[i][j-1].size()? dpTable[i-1][j]: dpTable[i][j-1];
                    
                }
                
            }
        }
        return dpTable[n1][n2];
    }
    
    
public:
   string shortestCommonSupersequence(string str1, string str2){
        string ans = "";
        string lcs = findLCS(str1,str2);
        
        int p1=0,p2=0;
        for(char c: lcs)
        {
            while(str1[p1]!=c)  //Add all non-LCS chars from str1
                ans += str1[p1++];
            while(str2[p2]!=c)  //Add all non-LCS chars from str2
                ans += str2[p2++];
            
            ans += c;   //Add LCS-char and increment both ptrs
            ++p1;
            ++p2;
        }
        ans += str1.substr(p1) + str2.substr(p2);
        return ans;
    }
    
};