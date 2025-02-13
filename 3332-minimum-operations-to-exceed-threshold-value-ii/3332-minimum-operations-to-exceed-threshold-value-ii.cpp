typedef long long ll;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operations = 0;
        priority_queue<ll, vector<ll>, greater<>> minHeap(nums.begin(), nums.end());

        while (minHeap.size() >= 2 && minHeap.top() < k) {
            operations++;

            ll x = minHeap.top();
            minHeap.pop();
            ll y = minHeap.top();
            minHeap.pop();

            minHeap.push(x * 2 + y);
        }

        return operations;
    }
};