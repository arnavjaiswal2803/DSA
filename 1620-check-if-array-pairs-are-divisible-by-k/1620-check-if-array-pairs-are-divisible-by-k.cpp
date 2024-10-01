class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freq;

        for (auto i : arr) freq[(i % k + k) % k]++;

        for (auto i : arr) {
            int rem = (i % k + k) % k;

            if (rem == 0) { 
                if (freq[rem] & 1) return false;
            } else if (freq[rem] != freq[k - rem]) return false;
        }

        return true;
    }
};