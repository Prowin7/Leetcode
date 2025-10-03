class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);
        int left=INT_MIN;
        int right=INT_MIN;
        for(int i=0;i<n;i++){
            left=max(left,height[i]);
            leftMax[i]=left;
            right=max(right,height[n-1-i]);
            rightMax[n-1-i]=right;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(leftMax[i],rightMax[i])-height[i];
        }
        return ans;
    }
};