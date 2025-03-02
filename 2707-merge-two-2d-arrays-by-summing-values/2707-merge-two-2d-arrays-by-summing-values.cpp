class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, 
                    vector<vector<int>>& nums2) {
        map<int, int> hash;
        for (auto &temp : nums1) hash[temp[0]] += temp[1];
        for (auto &temp : nums2) hash[temp[0]] += temp[1];
        
        vector<vector<int>> ans;
        for (auto &it : hash) ans.push_back({it.first, it.second});

        return ans;
    }
};