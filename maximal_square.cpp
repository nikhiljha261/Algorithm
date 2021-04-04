class Solution {
public:
    int maximalSquare(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int dp[r+1][c+1];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1')
                {
                    dp[i][j]=1;
                    ans=1;
                }
            }
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                int val=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                dp[i][j]=max(dp[i][j],val+dp[i][j]);
                if(grid[i][j]=='0') dp[i][j]=0;
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
        
    }
};
