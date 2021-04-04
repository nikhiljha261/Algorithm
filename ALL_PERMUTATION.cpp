class Solution {
public:
    // void fun(vector<vector<int>>& ans,vector<int>& nums,vector<int>& v,vector<bool>& vis)
    // {
    //     if(v.size()==nums.size())
    //     {
    //         ans.push_back(v);
    //         return ;
    //     }
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(vis[i]==false)
    //         {
    //             vis[i]=true;
    //             v.push_back(nums[i]);
    //             fun(ans,nums,v,vis);
    //             vis[i]=false;
    //             v.pop_back();
    //         }
    //     }
    // }
    void fun(int index,vector<vector<int>>& ans,vector<int>& nums)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            fun(index+1,ans,nums);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        fun(0,ans,nums);
        return ans;
    }
};
