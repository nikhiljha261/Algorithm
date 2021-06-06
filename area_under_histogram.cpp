#define ll long long
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long a[], int n)
    {
        stack<pair<ll,ll>> l;
        stack<pair<ll,ll>> r;
        vector<ll> left(n);
        vector<ll> right(n);
        left[0]=1;
        right[n-1]=1;
        l.push({a[0],0});
        for(ll i=1;i<n;i++)
        {
            if(l.top().first<a[i])
            {
                left[i]=i-l.top().second;
            }
            else
            {
                while(!l.empty() and l.top().first>=a[i])
                {
                    l.pop();
                }
                if(l.empty()==true)
                {
                    left[i]=i+1;
                }
                else
                {
                    left[i]=i-l.top().second;
                }
            }
            l.push({a[i],i});
        }
        r.push({a[n-1],n-1});
        for(ll i=n-2;i>=0;i--)
        {
            if(r.top().first<a[i])
            {
                right[i]=r.top().second-i;
            }
            else
            {
                while(!r.empty() and r.top().first>=a[i])
                {
                    r.pop();
                }
                if(r.empty()==true)
                {
                    right[i]=n-i;
                }
                else
                {
                    right[i]=r.top().second-i;
                }
            }
            r.push({a[i],i});
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        // for(int j=0;j<n;j++)
        // {
        //     cout<<right[j]<<" ";
        // }
        ll ans=INT_MIN;
        for(ll i=0;i<n;i++)
        {
            ll side=left[i]+right[i]-1;
            ll area=side*a[i];
            ans=max(ans,area);
        }
        return ans;
    }
}; 
