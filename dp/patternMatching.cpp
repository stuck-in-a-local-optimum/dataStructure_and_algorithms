
#include <iostream>
using namespace std;


                //-------determine if string P present in string S---------//
                /*-------observation-----------

                        if ( findLCS(P, Q)) == P, then return true otherwise false
                
                */


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

    bool patternMatching(string p,string q){
        string lcs = findLCS(p, q);
        if(p==lcs){
            return true;
        }
        return false;
    }

    int main(){

        cout<<patternMatching("aab",  "abbabb");


        return 0;
    }
        





