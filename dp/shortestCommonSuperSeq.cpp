

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

        //if were required to find the length of SCS then it would be len(SCS) = l1 + l3 - LCS
        
        int p1=0,p2=0;
        for(char c: lcs)
        {
            while(str1[p1]!=c){ //Add all non-LCS chars from str1
                ans += str1[p1++];
            }

            while(str2[p2]!=c){  //Add all non-LCS chars from str2
                ans += str2[p2++];
            }

            //so far our both pointers have reached the position where they matches with LCS-char 'c'
            ans += c;   //Add this LCS-char 
                       
            ++p1;       //and now increment both ptrs because this LCS-char were in both strings at respective position (p1 and p2 so far)
            ++p2;
        }    //keep repeating it till all LCS-char have been included in the ans only once


        ans += str1.substr(p1) + str2.substr(p2);  //now add the rest (chars right after LCS) chars of both string in ans
        return ans;                         
    }
    
};