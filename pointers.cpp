#include <iostream>
using namespace std;


    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

int main(){

        // int a=10;
        // int* aptr = &a;

        // cout<<*aptr<<endl;

        // *aptr = 20;

        // cout<<*aptr<<endl;

        int arr[] = {10, 20, 30};
        cout<<*arr<<endl;   //output: 10

        int *ptr = arr;

        for(int i=0; i<3;i++){
            cout<<*ptr<<endl;
            ptr++;
        }


        //pointer to pointer

        int a=2;
        int b=4;
            cout<<endl;
        swap(&a, &b);
        cout<<a<<" "<<b<<endl;


        



    return 0;
}