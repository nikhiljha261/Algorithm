//har har mahadev
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b)     for(int i=(a);i<(b);i++)
#define endl            "\n"
// #define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// cout<<fixed<<setprecision(9)<<" ";
// double rounded = std::floor((V * 100) + .5) / 100;

void ganeshji(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

//PAINTERS PARTITION

int sum(vector<int>& a,int n)
{
    int s=0;
    loop(i,0,n)
    {
        s+=a[i];
    }
    return s;
}
int maximum(vector<int>& a,int n)
{
    int maxi=INT_MIN;
    loop(i,0,n)
    {
        maxi=max(maxi,a[i]);
    }
    return maxi;
}
int countpainter(vector<int>& a,int n,int time)
{
    int p=1;
    int cur=a[0];
    loop(i,1,n)
    {
        if(cur+a[i]>time)
        {
            p++;
            cur=a[i];
        }
    }
    return p;
}

int countmintime(vector<int>& a,int n,int k)
{
    int h=sum(a,n);//min time
    int l=maximum(a,n);//max time
    while(l<=h)
    {
        int mid=(l+h)/2;//this is the time
        int co=countpainter(a,n,mid);//painters needed for this time
        if(co<=k)
        {
            h=mid-1;
        }
        else
        {
            l=mid;
        }
    }
    return l;
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
        vector<int> v(n);
        loop(i,0,n)
        {
            cin>>v[i];
        }
        int k;
        cin>>k;
        cout<<countmintime(v,n,k);
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}  
