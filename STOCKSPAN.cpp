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
        int a[n];
        loop(i,0,n)
        {
            cin>>a[i];
        }
        stack<pair<int,int>> st;
        vector<int> ans(n,1);
        loop(i,0,n)
        {
            if(st.empty())
            {
                ans[i]=i+1;
            }
            else if(st.top().first>=a[i])
            {
                ans[i]=abs(st.top().second-i);
                // st.push({a[i],i});
            }
            else
            {
                while(!st.empty() and st.top().first<a[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    ans[i]=i+1;
                }
                else
                {
                    ans[i]=abs(st.top().second-i);
                }
            }
            st.push({a[i],i});
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
