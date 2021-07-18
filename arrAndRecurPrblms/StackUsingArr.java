package arrAndRecurPrblms;

public class StackUsingArr {
    int[] arr = new int[1000];
    int[] minArr = new int[1000];
    int topPtr;
    int minPtr;

    public StackUsingArr(){
        this.topPtr=-1;
        this.minPtr =-1;
    }



    
    public static void main(String[] args){

    }


    public void  push(int num){
        this.arr[++topPtr] = num;  //increment the topPtr and add num to the arr

        if( minPtr>=0){    //if minPtr is not -1
            if(minArr[minPtr] > num){  //if new element is smaller than curr min
                minArr[++minPtr] = num;  
            }
            else{
                minArr[minPtr+1] = minArr[minPtr];  //else curr min is prev min
                minPtr++;
            }
        }
        else{
            minArr[++minPtr] = num;   //if minPtr=-1, then increment it
        }

    }


    public int getMin(){
        return arr[minPtr--];
        
    }

    // public void pop(){ 
    //     return arr[topPtr--];
       
    // }





    
}
