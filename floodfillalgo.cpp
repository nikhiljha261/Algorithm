// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int row;
    int col;
    int dr[4]={+1,-1,0,0};
    int dc[4]={0,0,+1,-1};
    int vis[105][105];
    void dfs(vector<vector<int>>& image, int x, int y, int newcolor,int oldcolor)
    {
        if(x>=row or y>=col or x<0 or y<0 or image[x][y]!=oldcolor)
        {
            return ;
        }
        vis[x][y]=1;
        image[x][y]=newcolor;
        for(int i=0;i<4;i++)
        {
            int nx=x+dr[i];
            int ny=y+dc[i];
            if(vis[nx][ny]==0)
            {
                dfs(image,nx,ny,newcolor,oldcolor);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        row=image.size();
        col=image[0].size();
        memset(vis,0,sizeof(vis));
        int oc=image[sr][sc];
        dfs(image,sr,sc,newColor,oc);
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
