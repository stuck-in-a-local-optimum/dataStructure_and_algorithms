#include <iostream>
using namespace std;


int main(){
        int n;
        cout<<"Enter value of n"<<endl;
        cin>>n;
        int i;
        for(i=2; i<n; i++){
            if(n%i==0){
                cout<<"non-prime!\n";
                break;
            }
        }
        if(i==n){
            cout<<"Prime!\n";
        }

        //ALL PRIME NUMBERS IN A GIVEN RANGE
        int a,b;
        cout<<"Enter two values a and b\n";
        cin>>a>>b;

        int j;
        for(int num=a; num<=b; num++){

                for(j=2; j<num; j++){
                    if(num%j==0){
                        break;  //non-prime
                    }

                }
                if(j==num){
                    cout<<num<<endl;
                }
        }


}
