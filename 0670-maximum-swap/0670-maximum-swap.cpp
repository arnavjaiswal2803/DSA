class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length(), maxIdx = n - 1, swapIdx1 = -1, swapIdx2 = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (str[i] > str[maxIdx]) maxIdx = i;
            else if (str[i] < str[maxIdx]) {
                swapIdx1 = i;
                swapIdx2 = maxIdx;
            }
        }

        if (swapIdx1 != -1 && swapIdx2 != -1) swap(str[swapIdx1], str[swapIdx2]);

        return stoi(str);
    }
};