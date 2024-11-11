class Solution {
    bool isPrime(vector<int> &sieve, int num) {
        return sieve[num] == num;
    }

    vector<int> createSieve() {
        const int N = 1001;
        vector<int> sieve(N);
        
        for (int i = 2; i < N; i++) sieve[i] = i;

        int greatestPrime = 2;
        for (int i = 2; i < N; i++) {
            if (isPrime(sieve, i)) {
                for (int j = 2; j * i < N; j++) sieve[j * i] = i;

                sieve[i] = greatestPrime;
                greatestPrime = i;
            } else sieve[i] = greatestPrime;
        }

        return sieve;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> sieve = createSieve();
        int n = nums.size(), prev = 0;

        for (int i = 0; i < n; i++) {
            if (prev >= nums[i]) return false;

            bool isReduced = false;
            for (int prime = sieve[nums[i]]; prime >= 2; prime = sieve[prime]) {
                if (nums[i] - prime > prev) {
                    prev = nums[i] - prime;
                    isReduced = true;
                    break;
                } else if (prime == 2) break;
            }
            if (!isReduced) prev = nums[i];
        }

        return true;
    }
};