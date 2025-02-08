class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        unordered_map<int, int> ballColorMap, colorFreq;

        for (int i = 0; i < n; i++) {
            int ball = queries[i][0], color = queries[i][1];

            if (ballColorMap.find(ball) != ballColorMap.end()) {
                int prevColor = ballColorMap[ball];
                colorFreq[prevColor]--;
                if (colorFreq[prevColor] == 0) colorFreq.erase(prevColor);
            }

            ballColorMap[ball] = color;
            colorFreq[color]++; 

            ans[i] = colorFreq.size();
        }

        return ans;
    }
};