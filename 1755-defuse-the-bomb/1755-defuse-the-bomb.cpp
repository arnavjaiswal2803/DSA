class Solution {
    int getTrueIdx(int idx, int n) { return (idx + n) % n; }
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(), replacement = 0;
        vector<int> ans(n, replacement);
        if (k == 0) return ans;

        int start, end;
        if (k > 0) {
            start = 1;
            end = 1;
        } else {
            start = k + n; 
            end = k + n;
        }

        for (int i = 0; i < abs(k); i++) {
            replacement += code[getTrueIdx(end, n)];
            end++;
        }

        for (int i = 0; i < n; i++) {
            ans[i] = replacement;

            replacement += (code[getTrueIdx(end, n)] - code[getTrueIdx(start, n)]);
            ++start;
            ++end;
        }

        return ans;
    }
};