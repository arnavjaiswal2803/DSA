class Solution {
    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = ((m + n) / 2) + ((m + n) % 2); // ceil
        while (gap > 0) {
            int i = 0, j = gap;
            while (j < m + n) {
                int* a = i < m ? &nums1[i] : &nums2[i - m];
                int* b = j < m ? &nums1[j] : &nums2[j - m];

                if (*a > *b) swap(a, b);
                i++;
                j++;
            }

            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2); // ceil
        }

        for (int i = m; i < m + n; i++) nums1[i] = nums2[i - m];
    }
};