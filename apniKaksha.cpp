#include <iostream>
using namespace std;

int main(){

        cout << "Hello guys "<< endl;
        int x=12;

        cout<<"size of int "<< sizeof(x)<<endl;
        

        /*
                ----------TYPE MODIFIERS-------
                signed -> 4 bytes
                unsigned -> 4 bytes  (size remains same but range increases because of no sign bit)
                short-> 2 bytes

        */
       short int si=12;
       long int li=12;
       cout<< "size of short int "<< sizeof(si)<<endl;
       cout<<"size of long int "<< sizeof(li)<<endl;
      


       //-----------------INPUT/OUTPUT------------------------
       int amount1;
       cout<<"Enter amount1\n";
       cin>>amount1;

       int amount2;
        cout<<"Enter amount2\n";
       cin>>amount2;

       int sum = amount1+amount2;
       cout<<"sum: "<<sum <<endl;

       //---------------------CONDITIONALS------------------
        int a,b,c;

        cout<<"Enter 3 numbers";
        cin>>a>>b>>c;

        if(a>b){
                if(a>c){
                        cout<<a<<endl;
                }
                else{
                        cout<<c<<endl;
                }
        }
        else{
                if(b>c){
                        cout<<b<<endl;
                }
                else{
                        cout<<c<<endl;
                }
        }

         
         return 0;
}