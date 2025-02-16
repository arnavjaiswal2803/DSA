class Solution {
    bool construct(int n, int idx, vector<int>& seq, vector<bool>& isNoUsed) {
        if (idx == 2 * n - 1) return true;
        if (seq[idx] != 0) return construct(n, idx + 1, seq, isNoUsed);

        for (int i = n; i >= 1; i--) {
            if (isNoUsed[i]) continue;
            
            isNoUsed[i] = true;
            seq[idx] = i;

            if (i == 1) {
                if (construct(n, idx + 1, seq, isNoUsed)) return true;
            } else {
                if (idx + i < 2 * n - 1 && seq[idx + i] == 0) {
                    seq[idx + i] = i;

                    if (construct(n, idx + 1, seq, isNoUsed)) return true;

                    seq[idx + i] = 0;
                }
            }

            seq[idx] = 0;
            isNoUsed[i] = false;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> seq(2 * n - 1, 0);
        vector<bool> isNoUsed(n + 1, false);
        
        construct(n, 0, seq, isNoUsed);

        return seq;
    }
};