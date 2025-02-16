class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size(), days = n / 4;
        long long totalWeight = 0;

        sort (pizzas.begin(), pizzas.end());

        int index = n - 1;
        for (int day = 1; day <= days; day += 2) {
            totalWeight += pizzas[index--];
        }

        index--; // Move to second heaviest pizza
        for (int day = 2; day <= days; day += 2) {
            totalWeight += pizzas[index];
            index -= 2;
        }

        return totalWeight;
    }
};