class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int max = *max_element(ranks.begin(), ranks.end());

        long long low = 1, high = max * (long long)cars * cars;
        while (low <= high) {
            long long mid = low + ((high - low) >> 1);

            if (canRepair(ranks, cars, mid)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }

private:
    bool canRepair(vector<int> &ranks, int cars, long long maxTime) {
        int repairedCars = 0;
        long long sqRoot = sqrt(maxTime);

        for (int &rank : ranks) {
            long long carsToRepair = sqRoot;
            while (rank * carsToRepair * carsToRepair > maxTime) carsToRepair--;
            repairedCars += carsToRepair;
            if (repairedCars >= cars) return true;
        }

        return false;
    }
};