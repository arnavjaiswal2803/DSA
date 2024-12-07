class Solution {
    int breakLocks(vector<int> strength, int K) {
        int mins = 0, swordEnergy = 0, x = 1;
        while (strength.size() > 0) {
            if (swordEnergy >= strength[0]) {
                strength.erase(strength.begin());
                if (strength.size() == 0) return mins;

                swordEnergy = 0;
                x += K;
            }

            int quotient = ceil((float)strength[0] / (float)x);
            swordEnergy += (x * quotient);
            mins += quotient;
        }
        return -1;
    }
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int minMins = INT_MAX, swordEnergy = 0, x = 1;

        sort(strength.begin(), strength.end());
        do {
            minMins = min(minMins, breakLocks(strength, K));
        } while (next_permutation(strength.begin(), strength.end()));

        return minMins;
    }
};