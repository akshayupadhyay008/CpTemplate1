#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, w; cin>>n>>w;
	int wt[n+1], value[n+1];
	int total_value=0;
	for(int i=0;i<n;i++){
		cin>>wt[i]>>value[i];
		total_value+=value[i];
	}
	int dp[total_value+1];
	dp[0]=0;
	for(int i=1;i<=total_value;i++)
		dp[i]=1e9+9;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=total_value;j>=value[i-1];j--){
			dp[j] = min(dp[j], dp[j-value[i-1]] + wt[i-1]);
			if(dp[j]<=w)
				ans=max(ans, j);
		}
	} 
	cout << ans << endl;
}