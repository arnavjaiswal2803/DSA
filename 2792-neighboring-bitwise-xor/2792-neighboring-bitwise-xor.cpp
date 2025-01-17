class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorr = 0;
        for (int &num : derived) xorr ^= num;
        return xorr == 0;
    }
};