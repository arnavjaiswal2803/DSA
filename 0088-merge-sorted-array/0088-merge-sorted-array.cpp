class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        
        int i = m - 1, j = 0;
        while (i >= 0 && j < n && nums1[i] > nums2[j]) {
            swap(nums1[i], nums2[j]);
            i--;
            j++;
        }

        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());

        for (int i = m; i < m + n; i++) nums1[i] = nums2[i - m];
    }
};