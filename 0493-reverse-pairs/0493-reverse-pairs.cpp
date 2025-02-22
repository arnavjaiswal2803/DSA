class Solution {
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp(high - low + 1);
        
        int i = low, j = mid + 1, k = 0;
        while (i <= mid & j <= high) {
            if (nums[i] < nums[j]) {
                temp[k] = nums[i];
                i++;
            } else {
                temp[k] = nums[j];
                j++;
            }
            k++;
        }

        while (i <= mid)
            temp[k++] = nums[i++];
        while (j <= high)
            temp[k++] = nums[j++];

        for (k = 0; k < high - low + 1; k++) {
            nums[low + k] = temp[k];
        }
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return 0;

        int mid = low + ((high - low) / 2);

        int count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);

        return count;
    }

    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int i = low, j = mid + 1;
        while (i <= mid & j <= high) {
            if (nums[i] <= 2 * (long)nums[j]) i++;
            else {
                count += mid - i + 1;
                j++;
            }
        }

        return count;
    }

public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};