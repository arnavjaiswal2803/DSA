class ProductOfNumbers {
    int size, lastZeroIdx;
    vector<int> prefixProd;
public:
    ProductOfNumbers() {
        size = 0;
        lastZeroIdx = -1;
    }
    
    void add(int num) {
        size++;

        prefixProd.push_back(num);
        if (size > 1 && prefixProd[size - 2] != 0) {
            prefixProd[size - 1] *= prefixProd[size - 2];
        }
        
        if (num == 0) lastZeroIdx = size - 1;
    }
    
    int getProduct(int k) {
        int idx = size - k;
        if (idx <= lastZeroIdx) return 0;
        if (idx == 0 || prefixProd[idx - 1] == 0) return prefixProd[size - 1];
        return prefixProd[size - 1] / prefixProd[idx - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */