class Solution {
    bool canDistribute(vector<int> &quantities, int storeCnt, int val) {
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
        int low = 0, high = *max_element(quantities.begin(), quantities.end());
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            canDistribute(quantities, n, mid) ? high = mid - 1 : low = mid + 1;
        }
        return low;
    }
};