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
    loop(tc,1,t+1)
    {
        int r,c;
        cin>>r>>c;
        int grid[r][c];
        set<pair<int,pair<int,int>>> s;
        loop(i,0,r)
        {
            loop(j,0,c)
            {
                int x;
                cin>>x;
                grid[i][j]=x;
                s.insert({-x,{i,j}});
            }
        }
        int ans=0;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(!s.empty())
        {
            auto ele=*s.begin();
            s.erase(s.begin());
            int h=-ele.first;
            int x=ele.second.first;
            int y=ele.second.second;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(x+dx[i]>=r or x+dx[i]<0 or y+dy[i]>=c or y+dy[i]<0)
                {
                    continue;
                }
                if(h-grid[nx][ny]<=1)
                {
                    continue;
                }
                else
                {
                    int diff=h-1-grid[nx][ny];
                    ans+=diff;
                    s.erase({-grid[nx][ny],{nx,ny}});
                    grid[nx][ny]=h-1;
                    s.insert({-grid[nx][ny],{nx,ny}});
                }
            }
        }
        cout << "Case #" << tc << ": ";
        cout<<ans<<endl;
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}

