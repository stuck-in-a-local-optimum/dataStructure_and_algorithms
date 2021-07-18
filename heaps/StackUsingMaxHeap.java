package heaps;

import java.util.PriorityQueue;
import java.util.*;

class StackUsingMaxHeap{


    Comparator<PqObject> myComparator = (a , b) ->{

        return b.key-a.key;
  };
      int timeStamp = 0;
      PriorityQueue<PqObject> pq = new PriorityQueue<>(myComparator);


      class PqObject{
          int key;
          int value;
          PqObject(int k, int v){
              this.key = k;
              this.value = v;
          }

      }

      


    public static void main(String[] args){
        StackUsingMaxHeap stack = new StackUsingMaxHeap();
        System.out.println(stack.size());

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.pop();
        System.out.println(stack.pop());

    }


        //push in O(1)
    public void push(int num){
        this.timeStamp++;
        pq.add( new PqObject(this.timeStamp, num));
    }


        //pop in O(logn)
    public int pop(){
        if(pq.size()==0){
            System.out.println("Stack is empty!");
            return -1;
        }
        PqObject top = pq.poll();
        return top.value;

    }

    public int size(){
        return pq.size();
    }





    





}