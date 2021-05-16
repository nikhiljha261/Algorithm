//har har mahadev
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b)     for(int i=(a);i<(b);i++)
#define endl            "\n"
// cout<<fixed<<setprecision(9)<<" ";
// double rounded = std::floor((V * 100) + .5) / 100;

void ganeshji(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}



int main()
{
    ganeshji();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    clock_t begin = clock();
    ll t=1;
    // cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=2;
        int prevz=1;
        int prevo=1;
        for(int i=2;i<=n;i++)
        {
            int temp=prevz;
            prevz=prevo;//ending with 0
            prevo=prevo+temp;//ewndinf with 1
            dp[i]=prevz+prevo;
        }
        cout<<dp[n]<<endl;
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}  
