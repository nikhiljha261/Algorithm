//BOTTOM UP
int knapSack(int W, int wt[], int val[], int n) 
{
    //TC:n*w
    //SC:2*W
    int dp[n+1][W+1];
    vector<int> prev(W+1,0);
    vector<int> cur(W+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1]>j)
            {
                cur[j]=prev[j];
            }
            else
            {
                cur[j]=max(val[i-1]+prev[j-wt[i-1]],prev[j]);
            }
        }
        prev.assign(cur.begin(),cur.end());
        fill_n(cur.begin(),W+1,0);
    }
    return prev[W];
}