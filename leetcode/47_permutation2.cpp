
void permute_r(vector<int>& nums, vector<int> &curr, vector<vector<int> > &results) {
    if (!nums.size()) {
        if (curr.size()) results.push_back(curr);
    }
    
    for (int i=0; i< nums.size(); i++) {
        int currNum = nums[i];
        nums.erase(nums.begin()+i);
        curr.push_back(currNum);
        
        permute_r(nums,curr,results);
        
        curr.erase(curr.end()-1);
        nums.insert(nums.begin()+i,currNum);
        while(i+1<nums.size() && nums[i+1] == currNum) i++;
    }
}

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > results;
        vector<int> curr;
        
        permute_r(nums,curr,results);
        
        return results;
    }
    
};