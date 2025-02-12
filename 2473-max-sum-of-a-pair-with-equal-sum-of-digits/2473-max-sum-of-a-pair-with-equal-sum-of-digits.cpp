class Solution {
    int getSumOfDigits(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), maxSum = -1;
        unordered_map<int, priority_queue<int, vector<int>, greater<>>> hash;

        for (int i = 0; i < n; i++) {
            int num = nums[i], digitSum = getSumOfDigits(num);
            auto &minHeap = hash[digitSum];
            minHeap.push(num);
            if (minHeap.size() > 2) minHeap.pop();
        }

        for (auto &it : hash) {
            auto &minHeap = it.second;
            if (minHeap.size() > 1) {
                int num1 = minHeap.top();
                minHeap.pop();
                int num2 = minHeap.top();
                minHeap.pop();

                maxSum = max(maxSum, num1 + num2);
            }
        }

        return maxSum;
    }
};