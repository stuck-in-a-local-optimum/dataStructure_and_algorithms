#include <iostream>
using namespace std;

int main(){

    int n;
     cout<<"Enter value of n"<<endl;
    cin>>n;

    /*for(int row=1; row<=n; row++){
        for(int col=1; col<=row; col++){
            if((row+col)%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    */


   //Rhombus pattern
   /*for(int row=1; row<=n;row++){
           int spaces = n-row;
           for(int space=1; space<=spaces; space++){
               cout<<" ";
           }
           for(int i=0; i<n; i++){
               cout<<"* ";
           }
           
        cout<<endl;
       }
       */

      //Palindromic pattern

      /* for(int row=1; row<=5; row++){
          int spaces = n-row;
          for(int space=0; space<spaces; space++){
              cout<<" ";
          }

          for(int i=row; i>=1; i--){
              cout<<i;
          }

          
          for(int i=2; i<=row; i++){
              cout<<i;
          }

          cout<<endl;

          
      }
      */

     

   
    

}