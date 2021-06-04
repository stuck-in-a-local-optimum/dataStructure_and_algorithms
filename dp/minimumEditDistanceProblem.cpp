#include <iostream>
using namespace std;

                /*----MINIMUM EDIT DISTANCE PROBLEM-------

                Goal: Convert string s1 to s2 in min. operations
                operations allowed: Insert, Remove, Replace 
                */


               /*------SOLUTION----------
               BOUNDARY CASES:
                    if m==0 then min operations needed is n
                            e.g s1="" , s2="abc" then min operations needed is 3 to convert s1 to s2

                similarly if n==0,
                        then min operations needed is m

                COMMON CASES:
                    i) same current char  (traversing from right to left)
                            if curr characters of two strings are same then
                            min operations needed = result(m, n) = result(m-1, n-1)
                            i.e we need not to do any change in that case.
                            e.g s1="abc", s2 = "bac"  then result(3, 3) = result(2, 2)

                    ii) if curr char are not match

                        In this case we need to take minimum of all three operations, insert, remove, replace
                            s1 = "abc", s2 = "bcd"
                        a) insert:
                                after insertion, s1 = "abcd" and s2 = "bc"
                                this means result(3,3) = result(3, 2)+1 becaues d have been matched inserted in s1 and 1 operation has been done
                            
                        b) remove:
                            after removal, s1 = "ab", s2="bcd", because d is still to be matched and 1 operation has been done.
                            result(3, 3) = result(2, 3)+1

                        c) replace:
                            after replacement, s1 = "abd", s2 = "bc", because d has been matched
                                result(3, 3) = result(2, 2)+1

                        NOw, we will take minimum of these three type of operations

               
               */



              int minEditDistance(string s1, string s2){
                  int m = s1.size();
                  int n = s2.size();

                  int result[m+1][n+1];

                  for(int row=0; row<=m; row++){
                        result[0][row] = row;
                  }

                  for(int col=0; col<=n; col++){
                      result[0][col] = col;
                  }

                  for(int i=1; i<=m; i++){
                      for(int j=1; j<=n; j++){
                          if(s1[i-1]==s2[j-1]){
                              result[i][j] = 0+result[i-1][j-1];
                          }
                          else{
                                 int firstMin = min( 1+ result[i][j-1], 1+ result[i-1][j]);
                                 result[i][j] = min(result[i-1][j-1]+ 1, firstMin);

                          }

                      }
                  }
                  return result[m][n];

                
              }



int main(){

    cout<<minEditDistance("abc", "bcd")<<"\n";







    return 0;
}