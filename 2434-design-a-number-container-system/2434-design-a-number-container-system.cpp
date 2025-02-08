class NumberContainers {
    unordered_map<int, int> idxNumMap;
    unordered_map<int, set<int>> numIdxsMap;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (idxNumMap.find(index) != idxNumMap.end()) {
            int oldNum = idxNumMap[index];
            numIdxsMap[oldNum].erase(index);
        }

        idxNumMap[index] = number;
        numIdxsMap[number].insert(index);
    }
    
    int find(int number) {
        return numIdxsMap[number].size() ? *(numIdxsMap[number].begin()) : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */