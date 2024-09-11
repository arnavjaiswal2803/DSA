class StackNode {
public:
    long val;
    StackNode *next;
    
    StackNode(long x, StackNode *node) {
        val = x;
        next = node;
    }
};

class MinStack {
    StackNode *topMost;
    int minVal;
public:
    MinStack() {
        topMost = NULL;
        minVal = INT_MAX;
    }
    
    void push(int val) {
        long valToInsert = val;
        if (val < minVal) {
            if (topMost != NULL) valToInsert = 2 * (long)val - minVal;
            minVal = val;
        }
        StackNode *node = new StackNode(valToInsert, topMost);
        topMost = node;
    }
    
    void pop() {
        if (topMost->val < minVal) minVal = 2 * (long)minVal - topMost->val;
        StackNode *temp = topMost;
        topMost = topMost->next;
        delete temp;

        if (topMost == NULL) minVal = INT_MAX;
    }
    
    int top() {
        return topMost->val < minVal ? minVal : topMost->val;
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */