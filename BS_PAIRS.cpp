//har har mahadev
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b)     for(int i=(a);i<(b);i++)
#define endl            "\n"

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
        ll l,r;
        cin>>l>>r;
        ll a[n];
        loop(i,0,n)
        {
          cin>>a[i];
        }
        sort(a,a+n);
        ll ans=0;
        loop(i,0,n-1)
        {
            ll high=n-1;
            ll low=i+1;
            ll ind=i;
            while(low<=high)
            {
                ll mid=(high-low)/2+low;
                // mid=mid+low;
                if(a[mid]+a[i]>=l and a[mid]+a[i]<=r)
                {
                    ind=mid;
                    high=mid-1;
                }
                else if(a[mid]+a[i]>r)
                {
                    high=mid-1;
                }
                else if(a[mid]+a[i]<l)
                {
                  low=mid+1;
                }
            }
            ll high1=n-1;
            ll low1=i+1;
            ll ind1=i;
            while(low1<=high1)
            {
                ll mid=(high1-low1)/2+low1;
                // mid=mid+low1;
                if(a[mid]+a[i]>=l and a[mid]+a[i]<=r)
                {
                    ind1=mid;
                    low1=mid+1;
                }
                else if(a[mid]+a[i]>r)
                {
                    high1=mid-1;
                }
                else if(a[mid]+a[i]<l)
                {
                  low1=mid+1;
                }
            }
            // cout<<ind<<" "<<ind1<<endl;
            if(ind==i)
            {
                ind=ind1;
            }
            // if(ind==i)
            if(ind1!=i) ans+=abs(ind1-ind)+1;
        }
        cout<<ans<<endl;

        
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
} 
