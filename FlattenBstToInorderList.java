/*  Structure of a Binary Search Tree node
class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
} */
class Solution {
    public Node flattenBST(Node root) {
        // code here
        Node prev=null;
        Node head=null;
        Stack<Node>st=new Stack<>();
        Node curr=root;
        while(curr!=null || !st.isEmpty()){
            while(curr!=null){
                st.push(curr);
                curr=curr.left;
            }
            curr=st.pop();
            if(prev==null){
                head=curr;
            }
            else{
                prev.right=curr;
                prev.left=null;
            }
            prev=curr;
            curr=curr.right;
        }
        return head;
    }
}