class CustomStack {
    vector<int> stackArr, incrementArr;
    int top, capacity;
public:
    CustomStack(int maxSize) {
        stackArr = vector<int>(maxSize);
        incrementArr = vector<int>(maxSize, 0);
        top = -1;
        capacity = maxSize;
    }
    
    void push(int x) {
        if (top + 1 < capacity) stackArr[++top] = x;
    }
    
    int pop() {
        if (top <= -1) return -1;
        if (top > 0) incrementArr[top - 1] += incrementArr[top];
        int val = stackArr[top] + incrementArr[top];
        incrementArr[top] = 0;
        top--;
        return val;
    }
    
    void increment(int k, int val) {
        if (top <= -1) return;
        int idx = min(top, k - 1);
        incrementArr[idx] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */