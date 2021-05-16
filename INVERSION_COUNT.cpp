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
int c=0;
void merge(vector<int>& v,int l,int m,int r)
{

    // cout<<"hey"<<" ";
    int n1=m-l+1;
    int n2=r-m;
    int a[n1];
    int b[n2];
    loop(i,0,n1)
    {
        a[i]=v[l+i];
    }
    loop(j,0,n2)
    {
        b[j]=v[m+1+j];
    }
    int k=l;
    int i=0;
    int j=0;
    while(i<n1 and j<n2)
    {
        if(a[i]<=b[j])
        {
            v[k]=a[i];
            i++;
            k++;
        }
        else
        {
            v[k]=b[j];
            j++;
            k++;
            c=c+n1-(i);
        }
    }
    while(i<n1)
    {
        v[k]=a[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        v[k]=b[j];
        k++;
        j++;
    }
    return ;
}

void mergesort(vector<int>& v,int l,int r)
{
    if(l>=r)
    {
        return ;
    }
    int mid=(l+r)/2;
    mergesort(v,l,mid);
    mergesort(v,mid+1,r);
    merge(v,l,mid,r);
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
        vector<int> a(n);
        loop(i,0,n)
        {
            cin>>a[i];
        }
        mergesort(a,0,n-1);
        loop(i,0,n)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl<<c;
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}  
