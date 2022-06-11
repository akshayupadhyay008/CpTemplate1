class Solution {
public:
    const int N=20;
    const int M=20;
    int vis[N][M];
    int comp[N][M];
    int dx[4]=[1,-1,0,0];
    int dy[4]=[0,0,1,-1];
    
    void dfs(int x,int y,int n,int m,vector <vector <int>>&arr,int com){
        if (x<0 || y<0 || x>=n || y>=m || arr[i][j]==0) {
            return;
        }
        vis[x][y]=0;
        comp[x][y]=com;
        
        for(int i=0;i<4;i++) {
            if (!vis[x+dx[i]][y+dy[i]]) {
                dfs(x+dx[i] , y+dy[i] ,n ,m ,arr,com);
            }
        }
        
    }
    int getMaximumGold(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        
        // we can move up down left right 
        // we dont have negative values 
        // we cannot step into 0's 
        // so our grid is converted into various connected component 
        // and ans=max of (sum of each component)
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                vis[i][j]=0;
            }
        }
        
        int com=1;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (!vis[i][j] && arr[i][j]!=0) {
                    dfs(i,j,n,m,com);
                }
            }
        }
        
        map <int,int> m;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (arr[i][j] != 0) {
                    m[comp[i][j]]+=arr[i][j];
                }
            }
        }
        
        int ans=0;
        
        for(auto x: m){
            ans=max(ans,x)
        }
        
        return ans;
    }
};