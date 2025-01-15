class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int next = 0;
        int res = 0;
        int cur = 0;
        for(int i = 0;i<nums.size();++i){
            next = max(next,i+nums[i]);
            if(cur == i){
                if(cur!= nums.size()-1){
                    cur = next;
                    res++;
                    if(cur>=nums.size()-1) break;
                }else break;
            }
        }
        return res;
    }
};