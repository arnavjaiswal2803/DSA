class Solution {
    void count(string tiles, string curr, unordered_set<string>& hash) {
        hash.insert(curr);
        if (tiles.size() == 0) return;

        for (int i = 0; i < tiles.size(); i++) {
            string newTiles = tiles.substr(0, i) + tiles.substr(i + 1);
            count(newTiles, curr + tiles[i], hash);
        }
    }
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        unordered_set<string> hash;
        for (int i = 0; i < n; i++) {
            string newTiles = tiles.substr(0, i) + tiles.substr(i + 1);
            count(newTiles, to_string(tiles[i]), hash);
        }
        return hash.size();
    }
};