#include<bits/stdc++.h>
using namespace std;


// int vis[20][20];
//     int comp[20][20];
//     int dx[4]={1,-1,0,0};
//     int dy[4]={0,0,1,-1};
    
//     void dfs(int x,int y,int n,int m,vector <vector <int>>&arr,int com){
//         if (x<0 || y<0 || x>=n || y>=m || arr[x][y]==0) {
//             return;
//         }
//         vis[x][y]=1;
//         comp[x][y]=com;
        
//         for(int i=0;i<4;i++) {
//             if (!vis[x+dx[i]][y+dy[i]]) {
//                 dfs(x+dx[i] , y+dy[i] ,n ,m ,arr,com);
//             }
//         }
        
//     }
//     int getMaximumGold(vector<vector<int>>& arr) {
//         int n=arr.size();
//         int m=arr[0].size();
        
//         // we can move up down left right 
//         // we dont have negative values 
//         // we cannot step into 0's 
//         // so our grid is converted into various connected component 
//         // and ans=max of (sum of each component)
        
//         for(int i=0;i<n;i++) {
//             for(int j=0;j<m;j++) {
//                 vis[i][j]=0;
//             }
//         }
        
//         int com=1;
        
//         for(int i=0;i<n;i++) {
//             for(int j=0;j<m;j++) {
//                 if (!vis[i][j] && arr[i][j]!=0) {
//                     dfs(i,j,n,m,arr,com);
//                 }
//             }
//         }
        
//         map <int,int> m1;
        
//         for(int i=0;i<n;i++) {
//             for(int j=0;j<m;j++) {
//                 if (arr[i][j] != 0) {
//                     m1[comp[i][j]]+=arr[i][j];
//                 }
//             }
//         }
        
//         int ans=0;
        
//         for(auto x: m1){
//             ans=max(ans,x.second);
//         }
        
//         return ans;
//     }

  int vis[20][20];
    int dp[20][20];
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    int solve(int i,int j,int n,int m,vector <vector <int> >& arr) {
        if (i<0 || j<0 || i>=n || j>=m || arr[i][j]==0) {
            return INT_MIN;
        }
        if (dp[i][j]!=-1) {
            return dp[i][j];
        }
        vis[i][j]=1;
        
        int mx=0;
        
        for(int k=0;k<4;k++) {
            // if (i+dx[k]>=0 && j+dy[k]>=0) {
                // if (!vis[i+dx[k]][j+dy[k]]) {
                    int val=solve(i+dx[k],j+dy[k],n,m,arr);
                    mx=max(mx,val!=INT_MIN?val:INT_MIN);
                // }
            //}
        }
        return dp[i][j]=mx+arr[i][j];
    }
    
    int getMaximumGold(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        
        for(int i=0;i<=n+2;i++){
            for(int j=0;j<=m+2;j++){
                vis[i][j]=0;
                dp[i][j]=-1;
            }
        }
        
        
        int ans=0;
        
        for(int i=0;i<=n+2;i++){
            for(int j=0;j<=m+2;j++){
                if (!vis[i][j] && !arr[i][j]){
                    ans=max(ans,solve(i,j,n,m,arr));
                }
            }
        }
        
        
        return ans;
    }

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;

    vector <vector <int>> arr(n,vector<int> (m));
    

    for (int i = 0; i < n; i++)
    {
        /* code */
        for (int j = 0; j < m; j++)
        {
            /* code */
            cin>>arr[i][j];
        }
        
    }
    int res=getMaximumGold(arr);
    cout<<res<<endl;
    
    return 0;
}