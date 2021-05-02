#include <iostream>
using namespace std;


//CATALAN NUMBERS: Cn = Sum(Ci.Cn-i) for i=0 to n-1
//C0 = 1, C1=1
//example:
// C2 = C0.C1 + C1.C0 = 2
// C3 = C0.C2 + C1.C1 + C2.C0 = 5
// C4 = C0.C3 + C1.C2 + C2.C1 + C3.C0 = 14



    //returns nth catalan //we will optimize it in DP
int catalan(int n){

    if(n==0 || n==1){
        return 1;
    }

    int res = 0;

    for(int i=0; i<=n-1; i++){
        res+= catalan(i)*catalan(n-i-1);

    }

    return res;

}

//APPLICATION OF CATALAN NUMBERS


//1 Possible BSTs for a given no. of nodes n





int main(){

    for(int i=0; i<10; i++){
        cout<<catalan(i)<<" ";
    }

    cout<<endl;
    return 0;
}