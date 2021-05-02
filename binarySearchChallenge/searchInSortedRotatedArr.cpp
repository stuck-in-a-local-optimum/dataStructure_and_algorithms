#include <iostream>
using namespace std;


/*----SEARCH IN SORTED AND ROTATED ARRAY------
    we are given an ascending sorted array that
    has been rotated from a pivot point (unknown to us)
    and an element X.
    Search for X in the array with complexity less than that of
    linear search!

    e.g 
    original array = [10, 20, 30, 40, 50], X=10
    rotated array = [30, 40, 50, 10, 20]

    clearly pivot element is 50.

    Answer: index=3
*/


/* ---STRATEGY----
1) find the pivot point
2) search for X by binary search in left half
3) search for X by binary search in right half


--------FINDING THE PIVOT POINT------
    pivot element: the element which is greater than its next element in rotatedArr i.e
                        rotatedArr[i]>rotatedArr[i+1], i<-n-1
*/


int searchInRotatedArr(int rotatedArr[], int left, int right, int key){
    if(left>right){
        return -1;
    }

    int mid = (left+right)/2;

    if(rotatedArr[mid]==key){
        return mid;
    }

    if ( rotatedArr[left] <= rotatedArr[mid]){  //check Are we in first half of rotatedArr (before pivot element)
        if(key>= rotatedArr[left] && key<=rotatedArr[mid]){  //check the key lies in first halft or not
            return searchInRotatedArr(rotatedArr, left, mid-1, key);
        }
        return searchInRotatedArr(rotatedArr, mid+1, right, key);
    }

    //else we are in second half of the rotated array (after the pivot point)
    if(key>=rotatedArr[mid] && key<=rotatedArr[right]){ //check , Is the key lies in the second half?
        return searchInRotatedArr(rotatedArr, mid+1, right, key);
    
    }
    return searchInRotatedArr(rotatedArr, left, mid-1, key);
}


int main(){

    int rotatedArr[] = {6, 7, 8, 9, 10, 1, 2, 5};
    int key = 1;
    int n= 8;

    int idx = searchInRotatedArr(rotatedArr, 0, n-1, key);

    if(idx==-1){
        cout<<"Key doesn't exists "<<endl;
    }
    else{
        cout<<"key is at index: "<<idx<<endl;
    }






    return 0;
}