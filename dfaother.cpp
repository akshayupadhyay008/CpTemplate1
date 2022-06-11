#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    // cout << "Total number of states:" << endl;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = 1;
    int f;
    // cout << "Total no of final states: " << endl;
    cin >> f;
    for (int i = 0; i < f; i++)
    {
        int st;
        // cout << "enter final state"
        //      << " " << i + 1 << endl;
        cin >> st;
        arr[st] = 2;
    }
    int curr = 2;
    map<int, int> m;
    for (int i = 1; i <= n; i++)
    {
        if (!m[arr[i]])
            m[arr[i]] = i;
    }

    for(auto x: m) {
        cout<<x.first<< "  "<<x.second<<endl;
    }
    cout<<endl;

    int state[n + 1][2];
    for (int i = 1; i <= n; i++)
    {
        // cout << "resulting states on input 0 and 1 respectively for state " << i << endl;
        int x, y;
        cin >> x >> y;
        state[i][0] = x;
        state[i][1] = y;
    }
    bool curr_change = true;
    while (curr_change)
    {
        int arr2[n + 1];
        for (int i = 0; i <= n; i++)
            arr2[i] = arr[i];
        curr_change = false;
        for (int i = 1; i <= n; i++)
        {
            if (m[arr[i]] != i)
            {
                bool found = false;
                for (auto j : m)
                {
                    if (arr[state[j.second][0]] == arr[state[i][0]] && arr[state[j.second][1]] == arr[state[i][1]])
                    {
                        found = true;
                        if (j.first != arr[i])
                            curr_change = true;
                        arr2[i] = j.first;
                        break;
                    }
                }
                if (!found)
                {
                    curr++;
                    arr[i] = curr;
                    m[curr] = i;
                    curr_change = true;
                }
            }
        }
        for (int i = 0; i <= n; i++)
            arr[i] = arr2[i];
    }
    cout << "Total states"
         << "->" << m.size() << endl;
    for (auto i : m)
    {
        cout << i.second << " " << state[i.second][0] << " " << state[i.second][1] << endl;
    }
}