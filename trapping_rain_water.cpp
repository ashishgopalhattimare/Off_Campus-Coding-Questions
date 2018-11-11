// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        
        int maxim = 0;
        for(int i = 0; i != height.size(); i++) {
            maxim = max(maxim, height[i]);
            leftMax[i] = maxim;
        }
        
        maxim = 0;
        for(int i = height.size()-1; i != -1; i--) {
            maxim = max(maxim, height[i]);
            rightMax[i] = maxim;
        }
        
        int result = 0;
        for(int i = 0; i < height.size(); i++) {
            result += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        
        return result;
    }
};