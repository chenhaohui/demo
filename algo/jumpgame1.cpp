class Solution {
public:
    bool canJump(vector<int>& nums) {
        //cover是覆盖范围 当前位置+可以走的步数 就是覆盖范围
        if(nums.size() == 1) return true;
        int cover = 0;
        for(int i = 0;i<=cover;i++){
            cover = max(cover,i+nums[i]);
            if(cover >= nums.size()-1) return true;
        }
        return false;
    }
};