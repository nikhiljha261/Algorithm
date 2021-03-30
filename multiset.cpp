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
        int n,w;
        cin>>n>>w;
        int a[n];
        multiset<int> s;
        loop(i,0,n)
        {
            cin>>a[i];
            s.insert(a[i]);
        }
        int ans=1;
        int left=w;
        while(!s.empty())
        {
            auto itr=s.upper_bound(left);
            if(itr!=s.begin())
            {
                itr--;
                int x=*itr;
                left=left-x;
                s.erase(itr);
            }
            else
            {
                ans++;
                left=w;
            }
        }
        cout<<ans<<endl;

    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}

