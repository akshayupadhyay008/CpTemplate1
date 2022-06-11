#include<bits/stdc++.h>
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(x,y) uniform_int_distribution<int>(x,y)(rng)
typedef pair<int,int> ii;

void tc()
{
    int n = 1000, m = 2000;
    cout << n << " " << m << endl;
    queue<int> q;
    int j = 1;
    q.push(j++);
    vector<ii> edges;
    while(j <= n) {
        int children = rnd(2,8);int x = q.front();
        q.pop();
        for(int i=0;i<children;i++) {
            int last = x;
            int len = rnd(1,50);
            for(int i=0;i<len;i++) {
                cerr << "j = " << j << endl;
                if(j > n) break;
                edges.push_back({j,last});
                last = j++;
            }
            q.push(last);
        }
        cerr << "j = " << j << endl;
    }
    cerr << "pkmkb\n";
    for(int i=0;i<n+1;i++) {
        int u = rnd(1,n);
        int v = rnd(1,n);
        while(u == v) {
            int u = rnd(1,n);
            int v = rnd(1,n);
            cerr << "u = " << u << endl << "v = " << v << endl;
        }
        cerr << "wefefewfwef\n";
        edges.push_back({u,v});
    }
    cerr << "wefwfw";

    // for(auto i:edges) cout << i.first << " " << i.second << " " << rnd(1,1000000000) << endl;
    // int qu = 200000;
    // cout << qu << endl;
    // for(int i=0;i<qu;i++) {
    //     cout << rnd(1,n) << " " << rnd(1,1000000000) << endl;
    // }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("testcases/1.in", "w", stdout);
    int t=5;
    cout << t << endl;
    while(t--) {
        tc();
    }
}