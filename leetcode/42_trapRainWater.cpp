class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size()<=2) return 0;
        
        int start = 0;
        int end = height.size()-1;
        int maxLeft = height[start];
        int maxRight = height[end];
        int water = 0;
        
        while (start <= end) {
            if (maxLeft < maxRight) {
                if (height[start] < maxLeft) {
                    water += maxLeft-height[start];
                } else maxLeft = height[start];
                
                start++;
            } else {
                if (height[end] < maxRight) {
                    water += maxRight-height[end];
                } else maxRight = height[end];
                
                end--;
            }
        }
        
        return water;
    }
};