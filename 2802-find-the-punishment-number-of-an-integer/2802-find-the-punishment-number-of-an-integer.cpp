class Solution {
    bool canPartition(string &numStr, int idx, int len, int sum, int target) {
        if (sum > target) return false;
        if (idx == len) return sum == target;

        int num = 0;
        for (int i = idx; i < len; i++) {
            num = (num * 10) + (numStr[i] - '0');
            if (canPartition(numStr, i + 1, len, sum + num, target)) return true;
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int punishmentNo = 0;
        for (int i = 1; i <= n; i++) {
            string numStr = to_string(i * i);
            int len = numStr.size();
            if (canPartition(numStr, 0, len, 0, i)) punishmentNo += (i * i);
        }
        return punishmentNo;
    }
};