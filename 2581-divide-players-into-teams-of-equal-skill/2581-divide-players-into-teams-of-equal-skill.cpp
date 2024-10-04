class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long chemistrySum = skill[0] * skill[n - 1];
        int left = 1, right = n - 2;
        while (left < right) {
            if (skill[left] + skill [right] != skill[0] + skill[n - 1]) return -1;
            chemistrySum += ((long long)skill[left] * (long long)skill[right]);
            left++;
            right--;
        }
        return chemistrySum;
    }
};