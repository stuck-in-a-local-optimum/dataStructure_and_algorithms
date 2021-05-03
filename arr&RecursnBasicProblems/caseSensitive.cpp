#include <iostream>
using namespace std;


int main(){

    string str = "afslfdbL";
        //change to upper case!
        cout<<'a'-'A'<<endl;

        for(int i=0; i<str.length(); i++){
            if(str[i]>='a'&& str[i]<='z'){
                str[i]-=32;
            }
        }

        cout<<str<<endl;


    return 0;
}