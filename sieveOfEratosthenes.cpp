#include <iostream>
using namespace std;


        void primeSieve(int n){

            int prime[100] ={0};

            for(int i=2; i<=n; i++){
                if(prime[i]==0){  //if not checked 
                    for(int j=i*i; j<=n; j+=i){   //then check its multiple from i^2 (all numbers before i^2 have been already checked)
                        prime[j]=1;
                    }
                }

            }

            for(int i=2; i<=n; i++){
                if(prime[i]==0){
                    cout<<i<<" ";
                }
            } cout<<endl;

        }


int main(){

    primeSieve(30);


    return 0;
}