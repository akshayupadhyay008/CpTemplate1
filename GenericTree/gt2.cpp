#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
 
#define ill int long long
#define ld long double

#define fi first 
#define se second 
#define pb push_back 

#define MP make_pair

// #define fo(i,k,n) for(ill i=k;i<n;i++)
// #define fr(i,n,k) for(ill i=n;i>=k;i--)
 
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
 
#define all(a) a.begin(),a.end()
#define pii pair<ill,ill>

#define vi vector<ill>
#define mii map<ill,ill>


#define intmax 2147483647
#define intmin -2147483648

#define inf ( (1e18) + 10)
#define neginf (-1 * (1e18 + 10))

#define pi 3.141592653589
#define mod 1000000007
// 998244353
// #define mod 998244353
#define endl '\n'

const ill N=1005;



ill data1[N]; // 1 based index 
vector <ill> adj[N]; // child 

ill currnode; // current node pointer value 1,2,3,4.....
ill root;

void construct_tree_from_euler(){
    vector <ill> sample{10,20,50,-1,60,-1,-1,30,70,-1,80,110,130,-1,-1,120,-1,-1,90,-1,-1,40,100,140,-1,-1,150,-1,-1,-1};

    stack <ill> s;

    currnode=1;

    for(auto x:sample){
        // we are not concerned about the data 
        // the node and the position of the node in the tree is represented bu the index ie the pointer ie the currnode
        if (x!=-1){
            // push pointers in the stack because they are main, not the data 
            if (s.empty()){
                data1[currnode]=x;
                root=currnode;
                s.push(currnode);
                currnode++;
            }
            else {
                data1[currnode]=x;
                adj[s.top()].pb(currnode);
                s.push(currnode);
                currnode++;
            }
        }
        else { // x==-1
            s.pop();
        }   
    }

    f1(i,1,15){
        cout<<i << "  " << data1[i]<<" -->  ";
        for(auto x:adj[i]){
            cout<<x<<"  ";
        }
        cout<<endl;
    }
    
}

void display(ill root){
    cout<<root<<" --> "<<data1[root]<<endl;

    for(auto x: adj[root]){
        display(x);
    }

}


ill ht_tree[N];

ill solve_height_subtree(ill root){

    ill height_x=0;

    for(auto x: adj[root]){
        height_x=max(height_x,1+solve_height_subtree(x));
    }

    ht_tree[root]=height_x;
    return height_x;
}

ill diameter;


ill solve_diameter(ill root){
    ill height_mx1=0;
    ill height_mx2=0;

    for(auto x: adj[root]){
        ill htt=1+solve_diameter(x);
        if (htt>height_mx1){
            height_mx2=height_mx1;
            height_mx1=htt;
        }
        else if (htt>height_mx2){
            height_mx2=htt;
        }
        // equality will also work ... 
        // if (htt>=height_mx1){
        //     height_mx2=height_mx1;
        //     height_mx1=htt;
        // }
        // else if (htt>=height_mx2){
        //     height_mx2=htt;
        // } 
    }
    
    cout<<root<< "   "<<height_mx1<< "   "<<height_mx2<< "   " << endl;
    diameter=max(diameter,height_mx1+height_mx2);

    return height_mx1;

}

void derive_diameter(){

    ill dummy = solve_height_subtree(root);

    cout<<endl;
    cout<<endl;
    f1(i,1,15){
        cout<<i<< "  " << ht_tree[i]<<endl;
    }
    cout<<endl;
    cout<<endl;



    ill dummy2=solve_diameter(root);
    cout<<diameter<<endl;
    cout<<endl;
    cout<<endl;

    // cout<<root<<endl;
}


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif  
    

    // parent not in the adjacency list --> input in the form of euler and -1 types 
    construct_tree_from_euler();

    cout<<endl;
    cout<<endl;

    display(root); // dfs on tree , preorder , euler path 

    derive_diameter();

    return 0;
}