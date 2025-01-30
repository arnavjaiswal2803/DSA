class Solution {
    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        
        int gap = ceil((float)(m + n) / 2.0), gapOneCount = 0;
        while (gapOneCount < 2) {
            int i = 0, j = gap;
            while (j < m + n) {
                int* a = i < m ? &nums1[i] : &nums2[i - m];
                int* b = j < m ? &nums1[j] : &nums2[j - m];

                if (*a > *b) swap(a, b);
                i++;
                j++;
            }
            gap = ceil((float)gap / 2.0);
            if (gap == 1) gapOneCount++;
        }

        for (int i = m; i < m + n; i++) nums1[i] = nums2[i - m];
    }
};