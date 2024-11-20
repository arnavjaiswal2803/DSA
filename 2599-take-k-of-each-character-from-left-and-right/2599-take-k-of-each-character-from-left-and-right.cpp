class Solution {
    bool areCharEnough(vector<int> &charFreq, int k) {
        return charFreq[0] >= k && charFreq[1] >= k && charFreq[2] >= k;
    }
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> charFreq(3, 0);

        for (int i = 0; i < n; i++) charFreq[s[i] - 'a']++;
        if (!areCharEnough(charFreq, k)) return -1;

        int left = 0, right = 0, maxWindowSize = 0;
        while (right < n) {
            charFreq[s[right] - 'a']--;
            while (!areCharEnough(charFreq, k)) {
                charFreq[s[left] - 'a']++;
                left++;
            }
            int windowSize = right - left + 1;
            maxWindowSize = max(maxWindowSize, windowSize);
            right++;
        }
        
        return n - maxWindowSize;
    }
};