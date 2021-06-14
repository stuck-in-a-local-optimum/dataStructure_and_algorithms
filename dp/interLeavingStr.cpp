#include <iostream>
#include <unordered_map>
using namespace std;


            /*-----REQUIREMENTS
                1) Length of (s1+s2) = s3
                2) substring of s1 & s2 should be in the same order
                    in s3
                3) count of unique characters in (s1+s2), should be the same in s3
                */


               /*------two pointer technique with memoization------
            
               */



unordered_map<string, bool> mem;



          bool check( string s1, string s2, string s3, int len1, int len2, int len3, int p1, int p2, int p3){
              if(p3==len3){         //if s3 has been totally passed 
                  return (p1==len1 and p2==len2) ? true : false;  //check same is true for s1 and s2
              }

            string key = to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);

            if(mem.find(key)!=mem.end()){
                return mem[key];   //return the ans if already calculated
            }

            if(p1 == len1){ //if first string is completed
                    if( s2[p2] == s3[p3]){
                       return mem[key] = check(s1, s2, s3, len1, len2, len3, p1, p2+1, p3+1);
                    }
                    return mem[key] = false;
            }


             if(p2 == len2){ //if first string is completed
                    if( s1[p1] == s3[p3]){
                       return mem[key] = check(s1, s2, s3, len1, len2, len3, p1+1, p2, p3+1);
                    }
                    return mem[key] = false;
            }


            bool one = false;
            bool two = false;
            

            //in other cases we keep checking each char of p3 with each char of s1 & s2 that is they match or not
            if(s1[p1] == s3[p3])
                one =  check(s1, s2, s3, len1, len2, len3, p1+1, p2, p3+1);

             if(s2[p2] == s3[p3])
                two =  check(s1, s2, s3, len1, len2, len3, p1, p2+1, p3+1);



            
        return mem[key] = one || two;  //return and update the memoization map for each subproblem

          }










bool isInterleaving( string s1, string s2, string s3){
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();

    if(len3 != len1 + len2){
        return false;
    }

    return check(  s1, s2, s3, len1,  len2,  len3, 0, 0, 0);

}






int main(){




    return 0;
}




