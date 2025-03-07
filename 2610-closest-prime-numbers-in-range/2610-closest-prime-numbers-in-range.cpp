class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) primes.push_back(i);
        }

        int numPrimes = primes.size();
        if (numPrimes < 2) return {-1, -1};

        vector<int> ans = {primes[0], primes.back()};
        for (int i = 1; i < numPrimes; i++) {
            if (primes[i] - primes[i - 1] < ans[1] - ans[0]) {
                ans[1] = primes[i];
                ans[0] = primes[i - 1];
            }
        }

        return ans;
    }

private:
    bool isPrime(int n) {
        if (n == 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
};