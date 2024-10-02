class MinStack {

    static class Node {
        int val;     // value element
        Node next;   // next 
    }

    Node top;

    public MinStack() {
        top = null;         // initialise the top as null
    }
    
    public void push(int val) {
        Node newNode = new Node();
        if (newNode == null){
            System.out.println("Stack Overflow");
        }
        else{
            newNode.val = val;
            newNode.next = top;
            top = newNode;
        }
    }
    
    public void pop() {
        if (top == null){
            System.out.println("Stack Underflow");
        }
        else{
            top = top.next;
        }
    }
    
    public int top() {
        if (top == null){
            System.out.println("Stack is empty");
        }
        
        return top.val;
    
    }
    
    public int getMin() {
        int min = Integer.MAX_VALUE;
        Node temp = top;
        while (temp != null){
            if (temp.val < min) min=temp.val;
            temp = temp.next;
        }    
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
