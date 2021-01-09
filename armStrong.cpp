#include <iostream>
#include <math.h>
using namespace std;


int main(){

    int n;

    cout<<"Enter an integer"<<endl;
    cin>>n;
    int originalNum = n;

    double sum;
     while(n>0){
         int lastDigit = n%10;
         sum+=pow(lastDigit, 3);
         n = n/10;
     }

     if(sum==originalNum){
         cout<<"Armstrong number"<<endl;
     }
     else{
         cout<<"Not Armstrong"<<endl;
     }

    return 0;
}