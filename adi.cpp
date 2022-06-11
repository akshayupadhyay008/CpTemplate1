// Author: Aditya Agrawal o_O
#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

/*
// Ordered-Set (PBDS)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define os_find(k) os.find_by_order(k)
#define os_order(k) os.order_of_key(k)
*/

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(x, y) uniform_int_distribution<long long int>(x, y)(rng)

// Debugger :/
#define debug(x)                \
    for (auto element : x)      \
        cout << element << " "; \
    cout << endl;
#define debugp(x)          \
    for (auto element : x) \
    cout << element.first << " " << element.second << endl
#define db(x) cout << #x << "=" << x << '\n'

typedef long long int lli;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<lli> vec;
typedef vector<pair<lli, lli>> vp;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<lli, lli> pii;
typedef map<lli, lli> mi;
typedef map<char, lli> mc;
typedef map<string, lli> ms;
#define f(i, k, n) for (lli i = k; i < n; i++)
#define fr(i, k, n) for (lli i = k; i >= n; i--)
#define gsort(x) sort(all(x), greater<lli>())
#define cntpop(x) __builtin_popcount(x)
#define nah cout << "NO" << endl
#define yeah cout << "YES" << endl
#define all(a) a.begin(), a.end()
#define mp(a, b) make_pair(a, b)
#define pb(k) push_back(k)
#define br cout << endl
#define endl '\n'
#define gcd __gcd
#define fo return
const int intmax = 2147483647;
const int intmin = -2147483648;
const int mod = 1000000007; //998244353;
const int pi = 3.141592653589;

lli power(lli a, lli b)
{
    lli p = 1;
    while (b)
    {
        if (b & 1 == 1)
            p *= a;
        a *= a;
        b = b >> 1;
    }
    return p;
}
lli modInv(lli i, lli m) { return power(i, mod - 2); }
lli fact[300000];
lli ncr(lli n, lli r) { return (n >= r ? (fact[n] * modInv(fact[r], mod)) % mod * modInv(fact[n - r], mod) % mod : 0); }
lli lcm(lli a, lli b) { return (a * b) / gcd(a, b); }
void in(vec &v) { f(i, 0, v.size()) cin >> v[i]; }
void in1(vec &v, lli n)
{
    f(i, 0, n)
    {
        lli h;
        cin >> h;
        v.pb(h);
    }
}
void out(vec v)
{
    f(i, 0, v.size()) cout << v[i] << ' ';
    cout << endl;
}

const int max_states = 50;

vector<pair<int, char>> adj[max_states]; // adjacency list

int vis[max_states];

int value[max_states][max_states];

map<pair<int, int>, vector<pair<int, int>>> dp;

void dfs(int root)
{
    vis[root] = 1;
    for (auto x : adj[root])
    {
        if (!vis[x.first])
        {
            dfs(x.first);
        }
    }
}

void backtract(int state1, int state2)
{
    for (auto x : dp[{state1, state2}])
    {
        value[x.first][x.second] = -1;
        backtract(x.first, x.second);
    }
}

int main()
{

    int num; // number of states
    cin >> num;

    int state[num];

    for (int i = 0; i < num; i++)
    {
        cin >> state[i];
    }

    int num_alphabet; // number of alphabets
    cin >> num_alphabet;

    // like A B ... or even 0 1 ...
    char alphabet[num_alphabet];

    for (int i = 0; i < num_alphabet; i++)
    {
        cin >> alphabet[i];
    }

    int start; // starting state
    cin >> start;

    int num_final; // number of final states
    cin >> num_final;

    int final_state[num_final]; // final states

    for (int i = 0; i < num_final; i++)
    {
        cin >> final_state[i];
    }

    // transition table
    int table[num][num_alphabet];

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num_alphabet; j++)
        {
            cin >> table[i][j];
        }
    }

    // checking for some unreachable node and removing them because we cannot reach them from starting state

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num_alphabet; j++)
        {
            adj[state[i]].push_back({table[i][j], alphabet[j]}); // 1 --> 2,A   3,B // 1 based indexing
        }
    }

    for (int i = 0; i < num + 5; i++)
    {               // because of 1 based indexing
        vis[i] = 0; // initially none is visited
    }

    cout << "Initial automata  -->  " << endl;

    cout << "Number of states - " << num << endl;

    cout << "States" << endl;

    for (int i = 0; i < num; i++)
    {
        cout << state[i] << "    ";
    }
    cout << endl;

    cout << "Number of Alphabets -  " << num_alphabet << endl;

    cout << "Alphabets " << endl;

    for (int i = 0; i < num_alphabet; i++)
    {
        cout << alphabet[i] << "    ";
    }
    cout << endl;

    cout << "Starting state -  " << start << endl;

    cout << "Final state count - " << num_final << endl;

    for (int i = 0; i < num_final; i++)
    {
        cout << final_state[i] << "   ";
    }
    cout << endl;

    cout << "transitions  - " << endl;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num_alphabet; j++)
        {
            cout << table[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;

    // calling dfs to find the unreachable nodes
    dfs(start);

    // now those who are still not visited are unreachable
    // vis[i]==0 then they are unreachable
    for (int i = 0; i < num; i++)
    {
        if (vis[state[i]] == 0)
        {
            state[i] = -1; // do not exist
        }
    }

    for (int i = 0; i < num + 2; i++)
    {
        for (int j = 0; j < num + 2; j++)
        {
            value[i][j] = 0; // 0 means they are not distinguisable now
        }
    }

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            int state1 = state[i];
            int state2 = state[j];

            if (state[i] == -1 || state[j] == -1)
            {
                continue; // non reachable states
            }

            int is_first_final = 0;
            int is_second_final = 0;
            for (int k = 0; k < num_final; k++)
            {
                if (final_state[k] == state1)
                {
                    is_first_final = 1;
                }
                if (final_state[k] == state2)
                {
                    is_second_final = 1;
                }
            }

            // cout<< state1<<"   " <<state2<<"   "<<is_first_final<< "   "<<is_second_final<< endl;

            if (is_first_final == 0 && is_second_final == 1)
            {
                value[state1][state2] = -1; // means they are distingusiable now / separate / cannot be merged / base case
            }
            else if (is_first_final == 1 && is_second_final == 0)
            {
                value[state1][state2] = -1;
            }
        }
    }

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            int state1 = state[i];
            int state2 = state[j];

            if (state[i] == -1 || state[j] == -1)
            {
                continue; // non reachable states
            }

            if (value[state1][state2] == -1)
            {
                continue;
            }
            else
            {

                for (int k = 0; k < num_alphabet; k++)
                {

                    // state1 goes to _ on this input
                    int output1 = table[i][k];

                    // state2 output on this input
                    int output2 = table[j][k];

                    if (output1 == output2)
                    {

                        continue;
                    }

                    if (output1 == state1 && output2 == state2)
                    {

                        continue;
                    }

                    if (output1 == state2 && output2 == state1)
                    {

                        continue;
                    }

                    if (output1 > output2)
                    {
                        swap(output1, output2);
                    }
                    // so combined state is    { output1,output2 } where output1<output2

                    if (value[output1][output2] == -1)
                    {
                        value[state1][state2] = -1;

                        // if you are marking this as -1 then you also have to backtract and mark others as -1 also whose value is stored there
                        // as so on they must also be having some values stored and they have to backtract also

                        for (auto x : dp[{state1, state2}])
                        {
                            value[x.first][x.second] = -1;
                            backtract(x.first, x.second);
                        }

                        // -1 then no need to check other inputs
                        break; // correct do please
                    }
                    else
                    {
                        // for backtracting purpose
                        // if later we got -1 there then we will put -1 here also
                        // continue;
                        dp[{output1, output2}].push_back({state1, state2});
                    }
                }
            }
        }
    }

    int parent[num];

    for (int i = 0; i < num; i++)
    {
        parent[i] = state[i];
    }

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            int state1 = state[i];
            int state2 = state[j];

            if (state1 == -1 || state2 == -1)
            {
                continue;
            }

            if (value[state1][state2] == -1)
            {
                continue; // cannot merge them
            }
            else
            {
                // parent of state1
                // parent of state2
                int parent1 = parent[i];
                int parent2 = parent[j];

                // make parent1 equal to parent2

                for (int k = 0; k < num; k++)
                {
                    if (parent[k] == parent1)
                    {
                        parent[k] = parent2;
                    }
                }
            }
        }
    }

    cout << "Final automata -- > " << endl;

    map<int, vector<int>> new_states;

    for (int i = 0; i < num; i++)
    {
        if (parent[i] != -1)
        {
            new_states[parent[i]].push_back(state[i]);
        }
    }

    int new_state_count = new_states.size();

    cout << "Number of new states - " << new_state_count << endl;

    cout << "New states " << endl;
    for (auto x : new_states)
    {
        cout << x.first << " -->  " << endl;
        for (auto y : x.second)
        {
            cout << y << "   ";
        }
        cout << endl;
    }

    map<int, int> isfinal; // 1 if final   0 if not final

    for (auto x : new_states)
    {
        isfinal[x.first] = 0;
    }

    // checking if final or not
    for (auto x : new_states)
    {
        int check = 0;
        for (auto y : x.second)
        {
            // check if y is final or not
            for (int i = 0; i < num_final; i++)
            {
                if (final_state[i] == y)
                {
                    check = 1;
                    break;
                }
            }
        }
        if (check)
        {
            isfinal[x.first] = 1;
        }
    }

    cout << "Final or not " << endl;

    for (auto x : isfinal)
    {
        cout << x.first << "  " << x.second << endl;
    }

    cout << endl;

    int new_start;
    for (auto x : new_states)
    {
        for (auto y : x.second)
        {
            // check if y is final or not
            if (y == start)
            {
                new_start = x.first;
                break;
            }
        }
        // break here also if you want
    }

    cout << "New start  -->  " << new_start << endl;

    // // finding a transition table
    map<int, vector<pair<char, int>>> final_adj;

    for (auto x : new_states)
    {
        // char checker=(*(x.second.begin()));
        int checker = x.first;
        // cout<<checker<<endl;

        int number_in_initial_state = -1;

        for (int i = 0; i < num; i++)
        {
            if (checker == state[i])
            {
                number_in_initial_state = i;
                break;
            }
        }

        for (int i = 0; i < num_alphabet; i++)
        {

            int going_to = table[number_in_initial_state][i];

            int state_of_going_to;
            for (auto k : new_states)
            {
                for (auto kk : k.second)
                {
                    if (going_to == kk)
                    {
                        state_of_going_to = k.first;
                        break;
                    }
                }
            }

            final_adj[checker].push_back({alphabet[i], state_of_going_to});
        }
    }

    cout << "Transitions  -- >  " << endl;

    for (auto x : final_adj)
    {
        cout << x.first << " --> " << endl;
        for (auto y : x.second)
        {
            cout << y.first << "  -  " << y.second << endl;
        }
        cout << endl;
    }

    return 0;
}