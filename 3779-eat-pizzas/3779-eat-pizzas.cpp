class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size(), days = n / 4;
        long long ans = 0;
        int evens = days / 2, odds = n - evens;

        sort (pizzas.begin(), pizzas.end());

        int day = 1, ptr = n - 1;
        while (day <= days) {
            ans += pizzas[ptr];
            ptr--;
            day += 2;
        }
        ptr--;

        day = 2;
        while (day <= days) {
            ans += pizzas[ptr];
            ptr -= 2;
            day += 2;
        }

        return ans;
    }
};