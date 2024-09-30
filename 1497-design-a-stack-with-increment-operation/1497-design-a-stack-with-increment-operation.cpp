class CustomStack {
    vector<int> arr;
    int top, capacity;
public:
    CustomStack(int maxSize) {
        arr = vector<int>(maxSize);
        top = -1;
        capacity = maxSize;
    }
    
    void push(int x) {
        if (top + 1 < capacity) arr[++top] = x;
    }
    
    int pop() {
        return top > -1 ? arr[top--] : -1;
    }
    
    void increment(int k, int val) {
        for (int i = 1; i <= k && i <= capacity; i++) arr[i - 1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */