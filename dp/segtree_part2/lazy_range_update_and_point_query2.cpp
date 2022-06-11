#include <bits/stdc++.h>
using namespace std;

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
 
// #pragma GCC target ("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
 
#define ill long long int 
#define ld long double

#define fi first 
#define se second 
#define pb push_back 

#define MP make_pair

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
#define PI 3.141592653589
#define mod 1000000007
// 998244353
#define md 998244353
#define endl '\n'

// google -->     cout<<"Case #"<<ic<<": "<<ans<<endl; 
// cout<<fixed<<setprecision(12)<<ans<<endl;

bool comp(const pair<ill,ill> &a, const pair<ill,ill> &b) {
    // ill val1=a.se-a.fi;
    // ill val2=b.se-b.fi;
    // // return (a.second < b.second);
    // if (val1>val2) {
    //     return true;
    // }
    // else {
    //     return false;
    // }
    
    // if (a.fi==b.fi) {
        // return (a.se>b.se);
    // }    

    if (a.fi != b.fi) {
        return a.fi<b.fi; 
    }
    else {
        ill d1=a.fi-a.se;
        ill d2=b.fi-b.se;

        if (d1>d2) {
            return true;
        }
        else {
            return false;
        }
        // return a.se<b.se;
    }
    
    // return a.fi<b.fi;
}

ill gcd(ill a, ill b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);     
}

ill binpow(ill a, ill b,ill m) {
    if (b == 0)
        return 1;

    ill res = binpow(a, b / 2,m);
    if (b % 2)
        return (res%m * res%m * a%m)%m;
    else
        return (res%m * res%m)%m;
}

ill be_rec(ill x,ill n) {
	if(n==0){
		return 1;
	}
	if(n%2==0){
		return be_rec((x*x),n/2);
	}
	return x*be_rec(x*x,(n-1)/2);
}

ill lcm(ill a,ill b) {
    return ((a/gcd(a,b))*b); // to avoid overflow 
}

ill modInv(ill i, ill m) {return binpow(i,m-2,m);}

// ill fact[2000005];
// ill ncr(ill n,ill r) {
//     return (n>=r?(fact[n]*modInv(fact[r],mod))%mod*modInv(fact[n-r],mod)%mod:0);
//     // return (n>=r?(fact[n]*modInv(fact[r],md))%md*modInv(fact[n-r],md)%md:0);
// }

// void initialise_fact(){
//     fact[0]=1;
//     fact[1]=1;
//     f0(i,2,2000005) {
//         fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
//         // fact[i]=((fact[i-1]%md)*(i%md))%md;
//     }
// }



// vector<int> prefix_function(string &s) {
    
//     int n = (int)s.length();
//     vector<int> pi(n,0);
    
//     for (int i = 1; i < n; i++) {
//         int j = pi[i-1];
//         while (j > 0 && s[i] != s[j])
//             j = pi[j-1];
//         if (s[i] == s[j])
//             j++;
//         pi[i] = j;
//     }

//     return pi;
// }


// vector <ill> lis(vector <ill> &v){
//     // lis in nlogn
//     ill n=v.size();
//     vector <ill> temp;

//     f0(i,0,n) {
      
//         auto it = upper_bound(all(temp), v[i]); // for non decreasing (increasing and equal will work)
//         // auto it = lower_bound(all(temp), v[i]); // for strictly increasing 
            
//         if (it == temp.end()) {
//             temp.pb(v[i]);
//         }
//         else {
//             *it = v[i];
//         }
//     }
//    return temp;
// }


// DSU ...

// const ill N=50005;
// // const int N=205;
// ill parent[N];
// ill size1[N];

// // vector <ill> adj[N];

// void make_set(ill v) {
//     parent[v] = v;
//     size1[v] = 1;
//     // adj[v].pb(v);
// }

// ill find_set(ill v) {
//     if (v == parent[v]) {
//         return v;
//     }
//     return parent[v] = find_set(parent[v]);
// }

// void union_set(ill a,ill b) {
//     a = find_set(a);
//     b = find_set(b);

//     if (a != b) {
//         if (size1[a] < size1[b]) {
//             swap(a, b);
//         }
        
//         parent[b] = a;
//         size1[a] += size1[b]; // updating the size of b is of no use because we will not use it anyway now 
//         // as when we will be asked to do sth with b we will operate on its parent b 
//         // size1[b] += size1[a];

//         // for(auto x: adj[b]) {
//         //     adj[a].pb(x);
//         // }

//         // adj[b].clear();
//     }
// }

struct segtree {
    ill size;

    vector <ill> tree; 
    // this stores the operation to be applied at that node  
    // if a node does not have any operation then we can use 
    // another bool array of 0 or 1 which tells whether this node has a operation or it does not 
    // another way to signify whether the current node has a operation or not is to store a particular value that will signify no operation 
    ill no_opertation; 

    void init(ill n) {
        size=1;
        no_opertation=-1; // can neutral element for the operation 

        while(size<n) {
            size=size*2;
        }

        // tree.assign(2*size+1,0LL);
        tree.assign(2*size+1,no_opertation);
    }


    ill get(ill index,ill x,ill lx,ill rx) { // index is used to direct which side to get 
        if (lx==rx) {
            return tree[x];
        }

        ill mid=(lx+rx)/2;
        ill res;
        if (index <= mid) {
            res = get(index,2*x,lx,mid);
        }
        else {
            res = get(index,2*x+1,mid+1,rx);
        }

        // return max(res,tree[x]); // here we need to merge two operation 
        // since we are maintaining the property that at the top we will have new operation and at the down we will have old operation and we are calling down 
        // so res is old 
        // tree[x] is new 
        ill oldOp = res;
        ill newOp = tree[x];
        // how to merge two operation 
        if (oldOp == no_opertation) {
            return newOp;
        }
        if (newOp == no_opertation) {
            return oldOp;
        }
        // else combine 
        // here we have assignment so we will take the new operation 
        return newOp;

    }

    ill get(ill index) { // get the value at the index index 
        return get(index,1,1,size); 
        // x lx rx  --> range answer stored by x node
        // x --> 1 based 
        // [lx,rx] --> both inclusive 
    }



    ill get2(ill index,ill x,ill lx,ill rx) { // index is used to direct which side to get 
        // propagate the operation 
        // and then all the result will reach the leaf node so just return the result from there 
        // all the path will have nothing 

        propagate(x,lx,rx); // you can write this to all the functions at the start only as it is fine and not doing anything just propagating the operation (also handles all cases inside)

        if (lx==rx) {
            return tree[x];
        }

        ill mid=(lx+rx)/2;
        ill res;
        if (index <= mid) {
            res = get2(index,2*x,lx,mid);
        }
        else {
            res = get2(index,2*x+1,mid+1,rx);
        }

        return res; // whatever we get from the leaf 
    }

    ill get2(ill index) { // get the value at the index index 
        return get2(index,1,1,size); 
        // x lx rx  --> range answer stored by x node
        // x --> 1 based 
        // [lx,rx] --> both inclusive 
    }

    
    void propagate(ill x,ill lx,ill rx) { 
        // x so that we know the node of left and right child 
        // x --> left = 2x+1     right --> 2x+2
        // lx and rx to find that whether this is leaf node or not --> if lx==rx this is leaf 
        if (lx == rx) {
            return; // leaf node no need to propagate 
        }

        if (tree[x] == no_opertation) { // if the node has no operation then no need to propagate 
            return;
        }

        // else 
        // propagate the result to left child and right child 
        // and set your value as no_operation because the result has been propagated to the childs 

        // 1 
        // propagating the result to the left child 
        ill oldOp = tree[2*x];
        ill newOp = tree[x];
        if (oldOp == no_opertation) {
            tree[2*x] = newOp;
        }
        else if (newOp == no_opertation) {
            tree[2*x] = oldOp;
        }
        // else combine 
        // here we have assignment so we will take the new operation 
        else {
            tree[2*x] = newOp;
        }

        // 2
        // propagating the result to the right child 
        oldOp = tree[2*x + 1];
        newOp = tree[x];
        if (oldOp == no_opertation) {
            tree[2*x + 1] = newOp;
        }
        else if (newOp == no_opertation) {
            tree[2*x + 1] = oldOp;
        }
        // else combine 
        // here we have assignment so we will take the new operation 
        else {
            tree[2*x + 1] = newOp;
        }

        // 3 
        // seting my operation to null
        tree[x] = no_opertation;
    }


    void range_update(ill l,ill r,ill val,ill x,ill lx,ill rx) { // add val to the range [l,r]
        if (l>rx || r<lx) { // no intersection --> nothing 
            return;
        }

        if (lx >= l && rx <= r) { // complete intersection --> add it here and return 
            // tree[x] = max(tree[x],val); // #merge 2 operation
            ill oldOp = tree[x];
            ill newOp = val;
            // how to merge two operation 
            // this is an assignment operation --> so takes the new value 
            tree[x] = newOp;

            return;
        }


        // before going to both the sides 
        // we have to ensure that we propage the operation present in this node to the child nodes 
        // so as to maintain the order that the higher the operation the newer it is on a path from root to leaf 
        propagate(x,lx,rx); // index, left of index, right of index 


        ill mid=(lx+rx)/2; // apply range update to both the parts on partial intersection 
        range_update(l,r,val,2*x,lx,mid);
        range_update(l,r,val,2*x+1,mid+1,rx);
    }

    void range_update(ill l,ill r,ill val) {
        range_update(l,r,val,1,1,size); 
        // l r --> actual query 
        // x --> node index 
        // lx rx --> answer of the range stored in node x 
    }

    void print() {
        ill i=0;
        for(auto x: tree) {
            cout<< i << " " << x << endl;
            i++;
        }
        cout<<endl;
    }
};


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);  // --> for taking input output from .txt

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif   

    // initialise_fact();
    // final_seive();

    ill tt=1; 
	// cin>>tt;
    
    f1(ic,1,tt) {

        ill num,q;
        cin>>num>>q;

        segtree s;
        s.init(num);

        // initially all are 0 
        f1(i,1,num) {
            s.range_update(i,i,0);
        }

        while(q--) {
            ill x;
            cin>>x;

            if (x==1) {
                ill l,r,val;
                cin>>l>>r>>val;
                l++; r++; // for 1 based 
                r--; // for r included bacause we have update for [l,r] and question gives [l,r)
                s.range_update(l,r,val);
            }
            else {
                ill idx;
                cin>>idx;
                idx++; // for 1 based 
                ill ans = s.get2(idx);
                cout << ans<<endl;
            }
        }

    }           
    return 0;
}