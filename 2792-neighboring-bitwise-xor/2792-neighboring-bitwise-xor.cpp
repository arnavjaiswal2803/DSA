class Solution {
    bool isPossible(vector<int>& derived, int first) {
        int curr = first, next;
        for (int &num : derived) {
            if (num == 1) next = curr == 1 ? 0 : 1;
            else next = curr == 1 ? 1 : 0;
            curr = next;
        }
        return next == first;
    }
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return isPossible(derived, 0) || isPossible(derived, 1);
    }
};