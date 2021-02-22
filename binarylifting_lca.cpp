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

vector<int> tree[200001];
int lvl[200001];
int up[200001][20];

void dfs(int src,int par,int l=0)
{
    lvl[src]=l;
    for(int child : tree[src])
    {
        if(child!=par)
        {
            dfs(child,src,l+1);
        }
    }
}

void binary_lifting(int src, int par)//lifting
{
    up[src][0] = par;
    for(int i = 1; i < 20; i++)
    {
        if(up[src][i-1] != -1)
            up[src][i] = up[up[src][i-1]][i-1];
        else up[src][i] = -1;
    }
 
    for(int child : tree[src])
    {
        if(child != par)
            binary_lifting(child, src);
    }
}


int lift_node(int node, int jump_required)//lifting
{
    for(int i = 19; i >= 0; i--){
        if(node == -1 || jump_required == 0)
        {
            break;
        }
        if(jump_required >= (1<<i)){
            jump_required-=(1<<i);
            node=up[node][i];
        }
    }
    return node;
}

int lca(int u,int v)//logn*logn
{
    if(lvl[u]<lvl[v])
    {
        swap(u,v);
    }
    u=lift_node(u,lvl[u]-lvl[v]);
    int l=0;
    int h=lvl[u];
    while(l!=h)
    {
        int mid=(l+h)/2;
        int x1=lift_node(u,mid);
        int x2=lift_node(v,mid);
        if(x1==x2)
        {
            h=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return lift_node(u,l);

}

int lca1(int u,int v)//logn
{
    if(lvl[u]<lvl[v])
    {
        swap(u,v);
    }
    u=lift_node(u,lvl[u]-lvl[v]);
    if(u==v)
    {
        return u;
    }
    for(int i=19;i>=0;i--)
    {
        if(up[u][i]!=up[v][i])
        {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return lift_node(u,1);
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
        binary_lifting(1, -1);
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}

