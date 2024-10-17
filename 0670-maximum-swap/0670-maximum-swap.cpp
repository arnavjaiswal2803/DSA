class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length();

        for (int i = 0; i < n - 1; i++) {
            int maxIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (str[j] >= str[maxIdx]) maxIdx = j;
            }

            if (maxIdx != i && str[maxIdx] != str[i]) {
                swap(str[i], str[maxIdx]);
                break;
            }
        }

        return stoi(str);
    }
};