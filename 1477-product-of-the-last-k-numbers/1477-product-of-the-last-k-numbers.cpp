class ProductOfNumbers {
    vector<int> nums;
    int size;
public:
    ProductOfNumbers() {
        size = 0;
    }
    
    void add(int num) {
        size++;
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int product = 1;
        for (int i = size - 1; i >= size - k; i--) product *= nums[i];
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */