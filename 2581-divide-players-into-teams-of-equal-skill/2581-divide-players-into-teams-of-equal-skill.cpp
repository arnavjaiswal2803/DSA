class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size(), numberOfTeams = n / 2, totalSkill = 0;
        vector<int> skillFreq(1001, 0);

        for (auto playerSkill : skill) {
            totalSkill += playerSkill;
            skillFreq[playerSkill]++;
        }

        if (totalSkill % numberOfTeams != 0) return -1;
        int targetSkill = totalSkill / numberOfTeams;

        long long chemistrySum = 0;
        for (auto playerSkill : skill) {
            int partnerSkill = targetSkill - playerSkill;
            if (skillFreq[partnerSkill] == 0) return -1;
            skillFreq[partnerSkill]--;
            chemistrySum += ((long long)playerSkill * (long long)partnerSkill);
        }

        return chemistrySum / 2;
    }
};