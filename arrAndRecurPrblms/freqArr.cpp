#include <iostream>
using namespace std;


int main(){

    string str = "alfsdflsafljalfs";

    int freqArr[26];

    for(int i=0; i<26; i++){
        freqArr[i]=0;
    }

    for(int i=0; i<str.length(); i++){
        freqArr[str[i]-'a']++;
    }

    for(int i=0; i<26; i++){
        char c = 'a'+i;
        cout<<c<<": "<<freqArr[i]<<endl;
    }




    return 0;
}