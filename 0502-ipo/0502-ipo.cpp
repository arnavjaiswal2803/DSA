auto maxHeapCmp =
    [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first < b.first) return true;
        else if (a.first > b.first) return false;
        else return a.second > b.second;
    };
auto minHeapCmp =
    [](pair<int, int>& a, pair<int, int>& b) {
        if (a.first > b.first) return true;
        else if (a.first < b.first) return false;
        else return a.second < b.second;
    };

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size(), currCapital = w, projectsDone = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            decltype(maxHeapCmp)> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            decltype(minHeapCmp)> minHeap;

        for (int i = 0; i < n; i++) {
            maxHeap.push({profits[i], capital[i]});
        }

        while (projectsDone < k && !maxHeap.empty()) {
            while (!maxHeap.empty() && currCapital < maxHeap.top().second) {
                int capitalReq = maxHeap.top().second;
                int potentialProfit = maxHeap.top().first;
                minHeap.push({capitalReq, potentialProfit});
                maxHeap.pop();
            }
            if (maxHeap.empty()) return currCapital;

            currCapital += maxHeap.top().first;
            maxHeap.pop();
            projectsDone++;

            while (!minHeap.empty() && minHeap.top().first <= currCapital) {
                int capitalReq = minHeap.top().first;
                int potentialProfit = minHeap.top().second;
                maxHeap.push({potentialProfit, capitalReq});
                minHeap.pop();
            }
        }

        return currCapital;
    }
};