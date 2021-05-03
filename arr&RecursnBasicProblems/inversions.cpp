#include <iostream>
using namespace std;

    long long merge(int arr[], int l, int mid, int h){

        int n1 = mid-l+1;
        int n2 = h-mid;

        int a[n1];
        int b[n2];

        long long inv=0;


        //make temporary arrays
        for(int i=0; i<n1; i++){
            a[i] = arr[i+l];
        }

         for(int i=0; i<n2; i++){
            b[i] = arr[mid+l+1];
        }

        int i=0; int j=0; int k=l;

        while(i<n1 && j<n2){
            if(a[i]<=b[j]){  //no inversion in this case
                arr[k] = arr[i];
                i++;
                k++;
            }
            else{   
                arr[k] = arr[j];
                inv+= n1-i;  //a[i]>a[k] && i<j 
                k++;
                j++;
            }

            while (i<n1){

                arr[k] = arr[i];
                k++;
                i++;


            }


            while (i<n2){

                arr[k] = arr[j];
                k++;
                j++;


            }
        
            
        }
        return inv;
    }


long long mergeSort(int arr[], int l, int h){
    long long inv= 0;

    if(l<h){
        int mid = (l+h)/2;

            inv+=mergeSort(arr, l, mid);   //left inverson
            inv+=mergeSort(arr, mid+1, h);  //right inversion
            inv+= merge(arr, l, mid, h);   //mixed inversion
    }
    return inv;

}




int main(){
    int n;
    cin>>n;


    int arr[n] ;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<mergeSort(arr, 0, n);


    return 0;
}