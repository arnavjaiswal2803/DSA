class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> maxHeap;
        for (auto num : nums) maxHeap.push(num);

        long long score = 0;
        while (k--) {
            int top = maxHeap.top();
            score += top;
            maxHeap.pop();
            maxHeap.push(ceil(top / 3.0));
        }

        return score;
    }
};