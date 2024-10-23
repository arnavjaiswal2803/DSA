class Solution {
    typedef pair<int, char> pic;
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pic, vector<pic>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string str = "";
        while (!pq.empty()) {
            pic top = pq.top();
            pq.pop();

            int n = str.length();
            char mostFreqChar = top.second;

            if (n >= 2 && str[n - 1] == mostFreqChar && str[n - 2] == mostFreqChar) {
                if (pq.empty()) break;

                pic currTop = pq.top();
                pq.pop();

                str += currTop.second;
                int newFreq = currTop.first - 1;
                if (newFreq > 0) pq.push({newFreq, currTop.second});

            }
            
            str += mostFreqChar;
            int updatedFreq = top.first - 1;
            if (updatedFreq > 0) pq.push({updatedFreq, mostFreqChar});
        }

        return str;
    }
};