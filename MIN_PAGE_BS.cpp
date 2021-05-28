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


bool min_std(vector<int> &a,int n,int m,int ans)
{
    int s=1;
    int cur=a[0];
    for(int i=1;i<n;i++)
    {
        if(cur+a[i]>ans)
        {
            s++;
            cur=a[i];
        }
        else
        {
            cur=cur+a[i];
        }
    }
    if(s<=m)
    {
        return true;
    }
    else
    {
        return false;
    }
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
        int m;
        cin>>m;
        vector<int> a(n);
        loop(i,0,n)
        {
            cin>>a[i];
        }
        int l=a[0];
        int h;
        for(int i=1;i<n;i++)
        {
            l=max(l,a[i]);
        }
        for(int j=0;j<n;j++)
        {
            h=h+a[j];
        }
        while(l<h)
        {
            int mid=l+(h-l)/2;//this is my max assigned with min.
            bool check=min_std(a,n,m,mid);
            if(check==true)
            {
                h=mid;
            }
            else
            {
                l=mid+1;
            }

        }
        cout<< l;
        
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}
