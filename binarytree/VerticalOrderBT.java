package binarytree;

import java.util.*;

public  class VerticalOrderBT {  //LEETCODE-987


    class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int val){
            this.val = val;
        }
    }


    
    static class MyPair{
    TreeNode node;
    int hd;
        int vd;
    MyPair(TreeNode node, int hd, int vd){
        this.node =node;
        this.hd = hd;
        this.vd = vd;
        
        }
}
    
        //order the elements in the priority queue in the following way:
        //if the vertical disance of two nodes is same give priority to the one with smaller node value
        //otherwise all the time, give priority to the one with smaller vertical distance
    Comparator<MyPair> myComparator  = (a, b) ->{
        if(a.vd==b.vd){
            return a.node.val-b.node.val;
        }
        return a.vd-b.vd;
    };
    
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        //to store the minimum and maximum possible horizontal distance from root node
        int min = 0;
        int max = 0;
        
        
        List<List<Integer> > ans = new ArrayList<>();
        
        if(root==null){
            return ans;
        }
        
        HashMap<Integer, PriorityQueue<MyPair> > myMap = new HashMap<>();

        //level order traversal

        Queue<MyPair> q = new LinkedList<>();
        
        q.add(new MyPair(root, 0, 0));
        
        
        while(q.size()!=0){
            MyPair curr = q.poll();
            TreeNode node = curr.node;
            int hd = curr.hd;
            int vd = curr.vd;
            

            //if map already contains the key for this hd , then add elements to the list
            if(myMap.containsKey(hd)){
                myMap.get(hd).add(curr);
            }
            else{
                    //else make a  new key, value pair
                PriorityQueue<MyPair> pq = new PriorityQueue<>(myComparator);

                pq.add(curr);
                myMap.put(hd, pq);
            }
            
            //if children exist then add them to queue
            if(node.left!=null){
                q.add(new MyPair(node.left, hd-1, vd+1));
                min = Math.min(hd-1, min);
            }
            
                        if(node.right!=null){
                q.add(new MyPair(node.right, hd+1, vd+1));
                            max = Math.max(max, hd+1);
            }
            
        }
        

        
        for(int i=min; i<=max; i++){
            ArrayList<Integer> t = new ArrayList<>();
            
            PriorityQueue<MyPair> pq = myMap.get(i);
            while(pq.size()!=0){
                t.add(pq.poll().node.val);
            }
            
            
            ans.add(t);

            
        }
        
        return ans;
        
    }
}










