//har har mahadev
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b)     for(int i=(a);i<(b);i++)
#define endl            "\n"
// cout<<fixed<<setprecision(9)<<" ";

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
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll h[n];
        loop(i,0,n)
        {
            cin>>h[i];
        }
        ll right[n];
        stack<pair<ll,ll>> s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.size()==0)
            {
                right[i]=-1;
            }
            else if(s.size()>0 and s.top().first>h[i])
            {
                right[i]=s.top().second;
            }
            else if(s.size()>0 and s.top().first<=h[i])
            {
                while(s.size()>0 and s.top().first<=h[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                {
                    right[i]=-1;
                }
                else
                {
                    right[i]=s.top().second;
                }
            }
            s.push({h[i],i});
        }
        int ans[n];
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n-1;i++)
        {
            int ind=right[i];
            if(ind==-1)
            {
                ind=n-1;
            }
            for(int j=i+1;j<=ind;j++)
            {
                if(h[i]==h[j])
                {
                    ans[i]++;
                    ans[j]++;
                }
            }
        }
        loop(i,0,n)
        {
            cout<<ans[i]<<" ";
        }

    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}

