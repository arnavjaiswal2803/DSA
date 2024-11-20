class Solution {
    bool areCharEnough(vector<int> &charFreq, int k) {
        return charFreq[0] >= k && charFreq[1] >= k && charFreq[2] >= k;
    }

    bool isPossible(string &s, int n, int k, int minutes) {
        vector<int> charFreq(3, 0);

        for (int i = 0; i < minutes; i++) charFreq[s[i] - 'a']++;
        if (areCharEnough(charFreq, k)) return true;

        for (int i = minutes - 1, j = n - 1; i >= 0; i--, j--) {
            charFreq[s[i] - 'a']--;
            charFreq[s[j] - 'a']++;
            if (areCharEnough(charFreq, k)) return true;
        }

        return false;
    }
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        
        int n = s.length(), low = 3, high = n;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);

            if (isPossible(s, n, k, mid)) high = mid - 1;
            else low = mid + 1;
        }

        return low <= n ? low : -1;
    }
};