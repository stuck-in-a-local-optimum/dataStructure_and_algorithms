
#include <iostream>
using namespace std;

                    /*-----LENGTH OF LONGEST SUBSEQUENCE OF GIVEN TWO STRINGS
                    */
class Solution {
public:

        int longestCommonSubseqRecur(string text1, string text2){
            //base case
            if( text1.size()==0 || text2.size()==0){
                return 0;
            }

            char a =  text1[0];
            char b = text2[0];
            int ans = 0;

            string str1 = text1.substr(1);
            string str2 = text2.substr(1);

            if(a==b){
                ans = 1+longestCommonSubseqRecur(str1, str2);
            }
            else{
                int p = longestCommonSubseqRecur(str1, text2);
                int q = longestCommonSubseqRecur(text1, str2);
                ans+=max( p, q);
            }

            return ans;
        }



    int longestCommonSubsequenceDp(string text1, string text2) {
        
        int n1 = text1.size();
        int n2 = text2.size();
        
        int dpTable[n1+1][n2+1];
        
        for(int row=0; row<=n1; row++){
            dpTable[row][0]=0;
        }
        
        for(int col=0; col<=n2; col++){
            dpTable[0][col]=0;
        }
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                    if(text1[i-1]==text2[j-1]){   //if equal then select both characters
                dpTable[i][j] = 1+dpTable[i-1][j-1];     
            }
            else{  //take max of both the possiblities by selecting only char from only one string to maintain longest LCS so far
                    //because let say if we skip that char from str1 then we may have lCS so far of length 1 and if we skip that char from str2 then we may have LCS so far of length 0, so will take the case which gives us the maximum lcs length
                    dpTable[i][j] = max(dpTable[i-1][j], dpTable[i][j-1]);  
                    
        }
        }
        }
        
    
        
        return dpTable[n1][n2];
        
    }

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
                if(str1[i]== str2[j]){
                    dpTable[i][j] = dpTable[i-1][j-1]+str1[i-1];

                }
                else{
                    dpTable[i][j] = dpTable[i-1][j].size() > dpTable[i][j-1].size()? dpTable[i-1][j]: dpTable[i][j-1];
                    
                }
                
            }
        }
        return dpTable[n1][n2];
    }
        
        
};

int main(){
    Solution *obj = new Solution();
    string str1 = "thisplkmrinted";
    string str2 = "whatthisqprinted";
    cout<<obj->longestCommonSubseqRecur(str1, str2)<<endl;
    cout<<obj->longestCommonSubsequenceDp(str1, str2)<<endl;
    cout<<obj->findLCS(str1, str2)<<endl;
    return 0;
}