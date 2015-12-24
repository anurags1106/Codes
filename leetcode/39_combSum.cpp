int vecSum(vector<int> &currList) {
    int sum = 0;
    for (int i=0; i<currList.size();i++) {
        sum += currList[i];
    }
    return sum;
}

void sum_r(vector<int> candidates, int target, vector<int> currentList, vector<vector<int>> &result) {
    int currSum = vecSum(currentList);
    if (currSum > target) return;
    if (currSum == target && currentList.size()) {
        sort(currentList.begin(),currentList.end());
        result.push_back(currentList);
        return;
    }
    
    int candidateSize = candidates.size();
    
    for (int i=0; i<candidateSize; i++) {
        currentList.push_back(candidates[0]);
        sum_r(candidates,target,currentList,result);
        currentList.erase(currentList.end()-1);
        candidates.erase(candidates.begin());
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currentList;
        vector<vector<int>> result;
        if(!candidates.size()) return result;
        sum_r(candidates, target, currentList,result);
        
        return result;
    }
};