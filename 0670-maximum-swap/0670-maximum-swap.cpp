class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length(), maxIdx = n - 1;

        vector<int> greater(n);
        greater[n - 1] = maxIdx;

        for (int i = n - 2; i >= 0; i--) {
            if (str[i] > str[maxIdx]) maxIdx = i;
            greater[i] = maxIdx;
        }

        for (int i = 0; i < n - 1; i++) {
            if (str[greater[i]] > str[i]) {
                swap(str[greater[i]], str[i]);
                break;
            }
        }



        return stoi(str);
    }
};