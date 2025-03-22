class Solution {
    typedef long long ll;
public:
    int maximumCandies(vector<int>& candies, long long k) {
        ll totalCandies = 0;

        for (int &pileSize : candies) totalCandies += pileSize;
        if (totalCandies < k) return 0;

        ll low = 1, high = totalCandies / k;
        while (low <= high) {
            int mid = (low + ((high - low) >> 1));

            if (canAllocate(candies, mid, k)) low = mid + 1;
            else high = mid - 1;
        }

        return (int)high;
    }

private: 
    bool canAllocate(vector<int>& candies, int toAllot, ll children) {
        ll pilesAlloted = 0;
        for (int &pileSize : candies) {
            pilesAlloted += (pileSize / toAllot);
            if (pilesAlloted >= children) return true;
        }
        return false;
    }
};