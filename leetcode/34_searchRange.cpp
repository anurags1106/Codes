class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        
        while (start<end) {
            int mid = (start+end)/2;
            if (nums[mid] < target) {
                start = mid+1;
            } else if (nums[mid] > target) {
                end = mid-1;
            } else {
                if (nums[mid-1] == target) end = mid-1;
                else {
                    end = mid;
                    break;
                }
            }
        }
        
        vector<int> result;
        if (nums[end] != target) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        result.push_back(end==-1?0:end);
        
        start = 0;
        end = nums.size()-1;
        
        while (start<end) {
            int mid = (start+end)/2;
            if (nums[mid] < target) {
                start = mid+1;
            } else if (nums[mid] > target) {
                end = mid-1;
            } else {
                if (nums[mid+1] == target) start = mid+1;
                else {
                    start = mid;
                    break;
                }
            }
        }
        
        //vector<int> result;
        result.push_back(start==nums.size()?nums.size()-1:start);
        
        return result;
    }
};