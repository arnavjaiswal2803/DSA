class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, int> inDeg;
        unordered_map<string, vector<string>> adjList;
    
        for (int i = 0; i < n; i++) {
            for (string &ingredient : ingredients[i]) {
                adjList[ingredient].push_back(recipes[i]);
                inDeg[recipes[i]]++;
            }
        }

        vector<string> possibleRecipes;
        queue<string> q;
        for (string &supply : supplies) q.push(supply);

        while (!q.empty()) {
            string ingredient = q.front();
            q.pop();

            for (string &recipe : adjList[ingredient]) {
                inDeg[recipe]--;
                if (inDeg[recipe] == 0) {
                    possibleRecipes.push_back(recipe);
                    q.push(recipe);
                }
            }
        }

        return possibleRecipes;
    }
};