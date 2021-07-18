#include  <iostream>
using namespace std;


int main(){

    char button;
    cout<<" Enter a character between a to d"<<endl;
    cin>>button;

    switch(button){
        case 'a':
        cout<<"a";
        break;
         
         case 'b':
         cout<<"b";
         break;

         case 'c':
         cout<<"c";
        break;
         case 'd':
         cout<<"d";
         break;
    }
}