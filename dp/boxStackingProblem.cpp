#include <iostream>
using namespace std;


                /*----------BOX STACKPROBLEM PROBLEM
                You are given a set of n types of rectangular 3-D boxes,
                where the i^th box has height h(i), width w(i) and depth 
                d(i) (all real numbers). 
                You want to create a stack of boxes which is as tall as 
                possible, but you can only stack a box on top of another 
                box if the dimensions of the 2-D base of the lower box are 
                each strictly larger than those of the 2-D base of the higher 
                box. Of course, you can rotate a box so that any side 
                functions as its base. It is also allowable to use multiple
                 instances of the same type of box. 

                 main constraints: 1) One box can be stacked o another onlyif lower box
                                    has strictly higher dimensions
                                    2) Rotation of box is allowed
                                    3) Multiple instances of same type of boxes are allowed.
                -----*/

                /*-------APPROACH-------------
                important observations:
                    1) we can't compare on the basis of base area 
                            if might be possible that base area of lower
                            box is higher B1 > B2 but w1<<<<<<<w2 (same with lenght)
                                than in that case we can't stack the boxes on each other.

                                So for B2 to stack on top of B1, we must have:
                                        a) w2 < w1
                                        b) l2 < l1

                            
                    2) since rotation of boxes is allowed so we can form max of
                        3 unique boxes by each box.


                //------ALGO--------  
                    1) Produce all rotations (for N boxes, 3N different cuboids can we formed by rotation)
                    2) arrange in asc/dsc based on base area so as to form largest pyramid possible
                    3) after sorting remove invalid boxes (invalid boxes are those which explains observation-1 above)
                        and this we can easily do by using LIS (LDS in case we sort it in dsc) concept (i.e skipping invalid boxes

                */

//representation of a box
struct Box{
    int h;
    int w;
    int l;
};


//compare function to compare boxes for sorting them in dsc order
bool compare(struct Box a, struct Box b){
    return (a.w*a.l > b.w*b.l) ? true : false;
}

int maxStackHeight(int height[], int width[], int lenght[], int n){
    // step-1 make an array of boxes (to store -> h, w, l)
    int len = 3*n;
    box arr[len];   //store all 3*n orientations

    int index=0;

    for(int i=0; i<len; i++){
        arr[index].h = height[i];   //ith box height
        arr[index].w = max(width[i], length[i]);      //to get the box of valid orientation stacking
        arr[index].l = min(width[i], length[i]);       // we are using min/max  
        index++;

        arr[index].h = width[i];   
        arr[index].w = max(length[i], height[i]);
        arr[index].l = min(length[i], height[i]);  
        index++;

        arr[index].h = length[i];   
        arr[index].w = max(height[i], width[i]);
        arr[index].l = min(height[i], width[i]);  
        index++;
    }


    //STEP-2 sort in dsc order of height
    sort( arr, arr+len, compare);


    //STEP-3 Find LIS (its actually longest descending subsequece but we are saying it LIS for simplicity)
    int lis[len];

    for(int i=0; i<len; i++){
        lis[i] = arr[i].h;

        for(int j=0; j<i; j++){
            if( (arr[i].w < arr[j].w) && (arr[i].l < arr[j].l) && (lis[i] < lis[j] + arr[i].h)){
                lis[i] = lis[j] + arr[i].h;
            }


        }

        int mx = 0;
        for(int i=0; i<len; i++){
            mx  = max( mx, lis[i]);
        }

        return mx;
    }
}






int main()
{
 
  return 0;
}
