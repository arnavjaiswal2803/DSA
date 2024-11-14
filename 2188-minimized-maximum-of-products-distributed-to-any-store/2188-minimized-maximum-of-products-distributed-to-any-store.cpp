class Solution {
    bool canDistribute(vector<int> &quantities, int storeCnt, long long val) {
        int prod = 0, prodQty = quantities[prod];
        for (int i = 0; i < storeCnt; i++) {
            if (val < prodQty) prodQty -= val;
            else if (val >= prodQty) {
                prod++;
                if (prod == quantities.size()) return true;
                prodQty = quantities[prod];
            }
        }
        return false;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int productsCount = quantities.size();
        long long sum = 0;

        for (int i = 0; i < productsCount; i++) sum += quantities[i];

        long long low = sum / n, high = sum;
        while (low <= high) {
            long long mid = low + ((high - low) / 2);

            canDistribute(quantities, n, mid) ? high = mid - 1 : low = mid + 1;
        }

        return (int)low;
    }
};