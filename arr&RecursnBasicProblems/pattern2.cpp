#include <iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter value of n"<<endl;

    cin>>n;

    for(int row=1; row<=n; row++){

            for(int col=1; col<=row; col++){
                cout<<"*";
            }

            int spaces = 2*n-2*row;
            for(int space=1; space<=spaces; space++){
                cout<<" ";
            }
            for(int col=1; col<=row; col++){
                cout<<"*";
            }
            cout<<endl;
    }

    for(int row=n; row>=1; row--){

            for(int col=1; col<=row; col++){
                cout<<"*";
            }

            int spaces = 2*n-2*row;
            for(int space=1; space<=spaces; space++){
                cout<<" ";
            }
            for(int col=1; col<=row; col++){
                cout<<"*";
            }
            cout<<endl;
    }
     


     
}