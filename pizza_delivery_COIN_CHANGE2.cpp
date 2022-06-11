// https://www.codechef.com/problems/DBOY
// https://discuss.codechef.com/t/dboy-editorial/1201

#include <bits/stdc++.h>
using namespace std;

#define long long long
const int inf = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;
        vector<long> h(n + 1), k(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> h[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> k[i];
        }

        vector<vector<long>> dp(n + 1, vector<long>(1010, inf));
        // dp[i][j] - min number of times to fill exactly j liters from the first i stations

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 1000; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (k[i] <= j)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - k[i]]);
                }
                //  note that when we are allowed to take a coin only once then we used to write -->     dp[i][j] = min(dp[i][j], 1 + dp[i-1][j - k[i]]);
                // dp[i-1] because we are dependent on the previous column
                // but now we write dp[i][j-k[i]] // which will in somewhere history derive from i-1 but we directly derive from [i] so to get the overall min ie [i]
            }
        }

        long res = 0;
        for (int i = 1; i <= n; i++)
            res += dp[n][2 * h[i]];
        cout << res << "\n";
    }
    return 0;
}


/*

// solution 2 :
int fuel(int n, vector<vector<int>> &dp, vi &v1)
{
    int sum = dp[0].size();
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 1e9;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j >= v1[i - 1])
            {
                if (dp[i][j - v1[i - 1]] != -1)
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - v1[i - 1]]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vi v(n), v1(n);
    read(v, n);
    read(v1, n);
    int sum = 0;
    vector<vector<int>> dp(n + 1, vector<int>(1001, -1));
    fuel(n, dp, v1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += dp[n][2 * v[i]];
    }
    cout << ans << "\n";

    return;
}

*/


/*

Editorial :: 

EXPLANATION
This is problem can be reduced to the traditional coin change problem. We have N types of coin, each having value K1, K2, …, and KN. We want to make changes for N days, each for 2 × H1, 2 × H2, …, and 2 × HN. What is the minimum number of coins needed?

Note that since each day is independent, we can minimize the number of coins on each day, and sum the results over N days.

Mathematically, for each day i, we want to minimize the value of

X1 + X2 + … + XN

subject to

X1K1 + X2K2 + … + XNKN = 2 × Hi

Xk ≥ 0 for 1 ≤ k ≤ N

We will use dynamic programming to solve this problem. Let dp[i][j] = the minimum number of coins needed to make changes for j, using only coins of types 1 through i. The base case is:

dp[0][0] = 0 (no coins needed)
dp[0][j] = infinity; for j ≠ 0 (it is impossible to make changes for j with no coins)
We can use a very large number such as 1,000,000,000 as infinity in our code.

We need to setup a recurrence relation. For each state dp[i][j], there are two possibilities:

We do not use any coin of type i. The minimum number of coins needed is then dp[i - 1][j].
We use at least one coin of type i. The minimum number of coins needed is then 1 + dp[i][j - Ki].
Therefore, we have

dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - Ki])

Both time and space complexity of this solution are in O(N × max{Hi}).

Here is a pseudocode of this solution.

read(N)
for i = 1; i ≤ N; i++:
    read(H[i])
for i = 1; i ≤ N; i++:
    read(K[i])

dp[0][0] = 0
for j = 1; j ≤ max{2 × H[i]}; j++:
    dp[0][j] = 1000000000
	
for i = 1; i ≤ N; i++:
    for j = 0; j ≤ max{2 × H[i]}; j++:
        dp[i][j] = dp[i-1][j]
        if K[i] ≤ j:
            dp[i][j] = min(dp[i][j], 1 + dp[i][j-K[i])

int res = 0
for i = 1; i ≤ N; i++:
    res = res + dp[N][2*H[i]]
println(res)
There is a solution that only uses O(max{Hi}) memory for the dp table. This solution uses the facts that:

dp[i][?] only refers dp[i-1][?]. So instead of keeping N rows in the DP table, we can store only the last two rows.
Furthermore, dp[i][x] only refers dp[i][y] for y < x. So we can store only the current row and fill the current row of the DP table from right to left.
read(N)
for i = 1; i ≤ N; i++:
    read(H[i])
for i = 1; i ≤ N; i++:
    read(K[i])

dp[0] = 0
for j = 1; j ≤ max{2 × H[i]}; j++:
    dp[j] = 1000000000
	
for i = 1; i ≤ N; i++:
    for j = K[i]; j < max{2 × H[i]}; j++:
        dp[j] = min(dp[j], 1 + dp[j-K[i])

int res = 0
for i = 1; i ≤ N; i++:
    res = res + dp[2*H[i]]
println(res)
Note that for the i-th row we fill the table from K[i] instead from 0. This is because for j &lt K[i] the DP values will not change.

Another solution is to use the so-called “forward DP”, i.e. filling the latter entries of the DP table using the values of the current entry. This is just a matter of style.

read(N)
for i = 1; i ≤ N; i++:
    read(H[i])
for i = 1; i ≤ N; i++:
    read(K[i])

dp[0] = 0
for j = 1; j ≤ max{2 × H[i]}; j++:
    dp[j] = 1000000000
	
for i = 1; i ≤ N; i++:
    for j = 0; j+K[i] < max{2 × H[i]}; j++:
        dp[j+K[i]] = min(dp[j+K[i]], 1 + dp[j])

int res = 0
for i = 1; i ≤ N; i++:
    res = res + dp[2*H[i]]
println(res)
In all solutions above, we do not remove duplicate coin types as they do not affect the answer, although they will make us recompute the same coin types in the DP table.

*/