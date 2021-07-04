https://leetcode.com/contest/weekly-contest-248/problems/build-array-from-permutation/

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int x=nums.size()+1;
        for(int i=0;i<x-1;i++)
        {
            int ov=nums[nums[i]];
            if(nums[i]<i) ov=nums[nums[i]]/x;
            nums[i]=(nums[i]*x)+ov;
        }
        for(int i=0;i<x-1;i++)
        {
            nums[i]=nums[i]%x;
        }
        return nums;
    }
};
