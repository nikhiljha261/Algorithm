        int n=s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++)
        {
            dp[i][i+1]=2;
        }
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<n-i+1;j++)
            {
                int k=j+i-1;
                if(s[j]==s[k])
                {
                    dp[j][k]=2+dp[j+1][k-1];
                }
                else
                {
                    dp[j][k]=max(dp[j+1][k],dp[j][k-1]);
                }
            }
        }
        return dp[0][n-1];
    }
