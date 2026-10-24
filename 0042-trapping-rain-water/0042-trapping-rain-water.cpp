class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int maxleft=0;
        int maxright=0;
        int water=0;
        while(left<right){
            if(height[left]<height[right]){
                maxleft=max(maxleft,height[left]);
                water+=maxleft-height[left];
                left++;
            }
            else{
                maxright=max(maxright,height[right]);
                water+=maxright-height[right];
                right--;
            }
        }
        return water;
    }
};