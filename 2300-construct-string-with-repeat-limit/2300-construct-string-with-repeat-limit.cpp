class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        vector<int> charFreq(26, 0);

        for (int i = 0; i < n; i++) charFreq[s[i] - 'a']++;

        priority_queue<pair<char, int>, vector<pair<char, int>>> maxHeap;
        for (int i = 0; i < 26; i++)
            if (charFreq[i] != 0) maxHeap.push({i + 'a', charFreq[i]});

        string repeatLimitedString = "";
        int currFreq = 0;
        while (!maxHeap.empty()) {
            char ch = maxHeap.top().first;
            int freq = maxHeap.top().second;
            maxHeap.pop();

            if (repeatLimitedString.size() > 0 &&
                repeatLimitedString.back() == ch &&
                currFreq + 1 > repeatLimit) {
                if (maxHeap.empty()) break;

                char ch2 = maxHeap.top().first;
                int freq2 = maxHeap.top().second;
                maxHeap.pop();

                repeatLimitedString += ch2;
                if (--freq2 > 0) maxHeap.push({ch2, freq2});
                currFreq = 0;
            }

            repeatLimitedString.size() > 0 && repeatLimitedString.back() == ch
                ? currFreq++
                : currFreq = 1;
            repeatLimitedString += ch;
            if (--freq > 0) maxHeap.push({ch, freq});
        }

        return repeatLimitedString;
    }
};