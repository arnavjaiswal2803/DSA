class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end()), 
            ansSet;

        for (int cnt = 0; cnt < n; cnt++) {
            for (int i = 0; i < n; i++) {
                if (ansSet.find(recipes[i]) != ansSet.end()) continue;
                
                bool canMake = true;
                for (string& ingredient : ingredients[i]) {
                    if (suppliesSet.find(ingredient) == suppliesSet.end()) {
                        canMake = false;
                        break;
                    }
                }
                if (canMake) {
                    ansSet.insert(recipes[i]);
                    suppliesSet.insert(recipes[i]);
                }
            }
        }

        vector<string> ans(ansSet.begin(), ansSet.end());
        return ans;
    }
};