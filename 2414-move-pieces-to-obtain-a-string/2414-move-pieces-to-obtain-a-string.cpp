class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        queue<pair<char, int>> s, t;

        for (int i = 0; i < n; i++) {
            if (start[i] != '_') s.push({start[i], i});
            if (target[i] != '_') t.push({target[i], i});
        }

        if (s.size() != t.size()) return false;

        while (!s.empty() && !t.empty()) {
            char startCh = s.front().first, targetCh = t.front().first;
            int startPos = s.front().second, targetPos = t.front().second;
            s.pop();
            t.pop();

            if (startCh != targetCh) return false;
            if (startCh == 'L' && startPos < targetPos) return false;
            if (startCh == 'R' && startPos > targetPos) return false;
        }

        return true;
    }
};