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
        //sort(currentList.begin(),currentList.end());
        result.push_back(currentList);
        return;
    }
    
    int candidateSize = candidates.size();
    int i=0;
    while (i<candidateSize) {
        currentList.push_back(candidates[0]);
        int prevVal = candidates[0];
        candidates.erase(candidates.begin());
        i++;
        sum_r(candidates,target,currentList,result);
        currentList.erase(currentList.end()-1);
        
        while (i<candidateSize && candidates[0] == prevVal){
            candidates.erase(candidates.begin());
            i++;
        }
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        if(!candidates.size()) return result;
        vector<int> currentList;
        
        sum_r(candidates, target, currentList,result);
        
        return result;
    }
};