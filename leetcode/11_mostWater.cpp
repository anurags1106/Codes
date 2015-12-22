class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxVal = -1;
        while(left < right) {
            int currentArea = (right-left)*min(height[left],height[right]);
            if (currentArea > maxVal) maxVal = currentArea;
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxVal;
    }
};