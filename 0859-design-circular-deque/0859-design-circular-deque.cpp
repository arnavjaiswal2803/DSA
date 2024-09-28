class MyCircularDeque {
    int capacity, size, rear, front;
    vector<int> arr;
public:
    MyCircularDeque(int k) {
        arr = vector<int>(k);
        capacity = k;
        size = 0;
        rear = -1, front = -1;
    }
    
    bool insertFront(int value) {
        if (size == capacity) return false;

        size++;
        if (size == 1) {
            rear = 0;
            front = 0;
        } else {
            front--;
            if (front < 0) front = capacity - 1;
        }
        arr[front] = value;
        return true; 
    }
    
    bool insertLast(int value) {
        if (size == capacity) return false;

        size++;
        if (size == 1) {
            rear = 0;
            front = 0;
        } else {
            rear++;
            if (rear == capacity) rear = 0;
        }
        arr[rear] = value;
        return true; 
    }
    
    bool deleteFront() {
        if (size == 0) return false;

        size--;
        if (size == 0) {
            front = -1;
            rear = -1;
        } else {
            front++;
            if (front == capacity) front = 0;
        }
        return true;
    }
    
    bool deleteLast() {
        if (size == 0) return false;

        size--;
        if (size == 0) {
            rear = -1;
            front = -1;
        } else {
            rear--;
            if (rear < 0) rear = capacity - 1;
        }
        return true;
    }
    
    int getFront() {
        return size > 0 ? arr[front] : -1;
    }
    
    int getRear() {
        return size > 0 ? arr[rear] : -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */