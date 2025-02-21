class Solution {
    void count(string tiles, string curr, int& ans) {
        ans++;
        if (tiles.size() == 0) return;

        for (int i = 0; i < tiles.size(); i++) {
            if (i > 0 && tiles[i] == tiles[i - 1]) continue;
            string newTiles = tiles.substr(0, i) + tiles.substr(i + 1);
            count(newTiles, curr + tiles[i], ans);
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size(), ans = 0;
        sort(tiles.begin(), tiles.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && tiles[i] == tiles[i - 1]) continue;
            string newTiles = tiles.substr(0, i) + tiles.substr(i + 1);
            count(newTiles, to_string(tiles[i]), ans);
        }
        return ans;
    }
};