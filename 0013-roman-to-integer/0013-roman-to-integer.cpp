class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};

        int sum = roman[s.back()];
        for (int i = s.length() - 2; i >= 0; i--)
            sum += roman[s[i]] < roman[s[i + 1]] ? -roman[s[i]] : roman[s[i]];

        return sum;
    }
};