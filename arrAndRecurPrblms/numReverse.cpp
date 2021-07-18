#include <iostream>
using namespace std;

int main(){

        int n;
        cout<<"Enter the number to reverse";
        cin>>n;
        int revNum=0;

        while(n>0){
            int lastDigit = n%10;  //this will fetch the lastdigit of n

            revNum = revNum*10+lastDigit;   
            n = n/10;   //this will delete the lastdigit from n that has been fetched            
        }
        cout<<revNum;



return 0;
}