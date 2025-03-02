class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int low = 1, high = 1e9;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);

            if (canMakeBouquets(bloomDay, n, m, k, mid)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }

private:
    bool canMakeBouquets(vector<int>& bloomDay, int numFlowers, int reqBouquets,
                         int reqFlowersInBouquet, int daysPassed) {
        int numBouquets = 0;
        for (int start = 0, end = 0; end < numFlowers; end++) {
            if (bloomDay[end] > daysPassed) {
                start = end + 1;
                continue;
            }

            int adjBloomedFlowers = end - start + 1;
            if (adjBloomedFlowers == reqFlowersInBouquet) {
                numBouquets++;
                if (numBouquets == reqBouquets) return true;
                
                start = end + 1;
            }
        }
        return false;
    }
};