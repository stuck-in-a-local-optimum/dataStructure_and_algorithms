#include <iostream>
using namespace std;


    //how many numbers b/w 1 and n are divisible by a or b  
    int divisible(int n, int a, int b){

        int c1 = n/a; //no. of numbers divisible by a
        int c2 = a/b; //no. of numbers divisible by b

        int c3 = n/(a*b);
        return c1+c2-c3;

    }


    int gcd(int a, int b){

        while(b!=0){
            int remainder = a%b;
            a = b;
            b = remainder;
        }
        return a;
    }


int main(){


        cout<<divisible(40, 5, 7)<<endl;

        cout<<gcd(42, 24)<<endl;




    return 0;
}