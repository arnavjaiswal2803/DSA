class Solution {
    bool getBit(long int mask, int pos) {
        return (mask & ((long int)1 << pos)) != 0;
    }

    void setBit(long int &mask, int pos) {
        mask |= ((long int)1 << pos);
    }
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), count = 0;
        long int mask = 0;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            if (getBit(mask, A[i])) count++;
            setBit(mask, A[i]);
            if (getBit(mask, B[i])) count++;
            setBit(mask, B[i]);
            ans[i] = count;
        }

        return ans;
    }
};