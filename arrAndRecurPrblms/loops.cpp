#include <iostream>
using namespace std;

int main(){

        //--------For loop-----------
        int n;
    cout<<"Enter the value of n\n";
     cin>>n;

     int sum=0;

     for(int i=1; i<=n; i++){
         sum+=i;
     }
     cout<<sum;

    //------------WHILE LOOP-------------
    int x;
    cout<<"enter non-negative value of x\n";
    cin>>x;

    while(x!=11){
        x++;
    }
    cout<<"value of x become"<<x;
    return 0;
}