class Solution {
    vector<int> calcXorOfAllElems(vector<int> &arr) {
        vector<int> xors;
        int xorr = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            xorr ^= arr[i];
            xors.push_back(xorr);
        }
        return xors;
    }
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans, xors = calcXorOfAllElems(arr);
        for (auto &query : queries) {
            int leftXor = query[0] > 0 ? xors[query[0] - 1] : 0;
            int rightXor = xors[query[1]];
            ans.push_back(leftXor ^ rightXor);
        }
        return ans;
    }
};