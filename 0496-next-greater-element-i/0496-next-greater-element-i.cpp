class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) hash[nums1[i]] = i;

        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = m - 1; i >= 0; i--) {
            while (!st.empty() && nums2[i] >= st.top()) st.pop();
            if (!st.empty() && hash.find(nums2[i]) != hash.end()) {
                ans[hash[nums2[i]]] = st.top();
            }
            st.push(nums2[i]);
        }

        return ans; 
    }
};