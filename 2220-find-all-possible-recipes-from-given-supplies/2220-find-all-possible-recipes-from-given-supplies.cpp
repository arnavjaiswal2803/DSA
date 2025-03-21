class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        int n = recipes.size(), ansSize = -1;
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end());
        vector<string> ans;

        while (ansSize != ans.size()) {
            ansSize = ans.size();
            
            for (int i = 0; i < n; i++) {
                if (suppliesSet.find(recipes[i]) != suppliesSet.end()) continue;
                
                bool canMake = true;
                for (string& ingredient : ingredients[i]) {
                    if (suppliesSet.find(ingredient) == suppliesSet.end()) {
                        canMake = false;
                        break;
                    }
                }
                if (canMake) {
                    ans.push_back(recipes[i]);
                    suppliesSet.insert(recipes[i]);
                }
            }
        }

        return ans;
    }
};