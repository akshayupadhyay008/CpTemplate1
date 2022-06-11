#include <bits/stdc++.h>
using namespace std;

void bfs()
{
    int n;
    vector<int> adj[n];

    queue<int> q;

    int vis[n];
    for (int i = 0; i < n; i++)
        vis[i] = 0;

    q.push(0);  // Assuming source_node=0
    vis[0] = 1; // visit the source node

    while (!q.empty())
    {
        int s = q.front();
        q.pop(); // remove front element of q, say s

        for (int i = 0; i < adj[s].size(); i++)
        {
            // visit all neighbours of s
            int ch = adj[s][i]; // new child
            if (vis[ch] == 0)
            { // if child is not visited, push to queue
                q.push(ch);
                vis[ch] = 1;
                // lev[ch]=lev[s]+1;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}