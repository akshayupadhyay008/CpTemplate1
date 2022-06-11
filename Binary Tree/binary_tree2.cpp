#include <bits/stdc++.h>
using namespace std;

// #pragma GCC target ("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")

#define ill int long long
#define ld long double

#define fi first
#define se second
#define pb push_back

#define MP make_pair

// #define fo(i,k,n) for(ill i=k;i<n;i++)
// #define fr(i,n,k) for(ill i=n;i>=k;i--)

#define f0(i, a, b) for (int i = a; i < b; i++)
#define f1(i, a, b) for (int i = a; i <= b; i++)
#define f2(i, a, b) for (int i = a; i > b; i--)
#define f3(i, a, b) for (int i = a; i >= b; i--)

#define all(a) a.begin(), a.end()
#define pii pair<ill, ill>

#define vi vector<ill>
#define mii map<ill, ill>

#define intmax 2147483647
#define intmin -2147483648

#define inf ((1e18) + 10)
#define neginf (-1 * (1e18 + 10))

#define pi 3.141592653589
#define mod 1000000007
// 998244353
// #define mod 998244353
#define endl '\n'

ill gcd(ill a, ill b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


ill lcm(ill a, ill b)
{
    return ((a / gcd(a, b)) * b); // to avoid overflow
}


const ill N = 1005;

// node is represented by the pointer
// pointer --> index 1 2 3 4 5 6 7
ill data1[N];  // data corres.. to node represented by i --> data=data1[i] (1 based )
ill left1[N];  // left child pointer(index)
ill right1[N]; // right child pointer(index)
ill root;      // root of the tree

void construct()
{
    vector<ill> v{50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    // -1 means no child there (left or right)
    stack<pair<ill, ill>> s;

    ill curr = 1;

    // while loop is better in stack
    // because index se not able to decide
    // decision is based on top

    root = curr; // root=1
    data1[curr] = v[0];
    s.push({curr, 0}); // 0 means have to put left child
    // 1 means has to put right child
    // 2 means has to pop this
    curr++;

    ill i = 1; // index in vector v

    while (1)
    {
        if (s.size() == 0)
        {
            break;
        }

        ill top_pointer = s.top().fi;
        ill top_state = s.top().se;

        if (top_state == 0)
        { // waiting for the left child
            if (v[i] != -1)
            {
                data1[curr] = v[i]; // new node inserted

                left1[s.top().fi] = curr; // the top node in stack has its left as this new node
                s.top().se++;             // the top node is now waiting for its right child

                // inserting this node in the stack
                s.push({curr, 0}); // this new node will be waiting for its left

                i++;    // index increase
                curr++; // future node pointer
            }
            else
            {
                left1[s.top().fi] = -1;
                s.top().se++; // the top node is now waiting for its right child

                i++;
            }
        }
        else if (top_state == 1)
        {
            if (v[i] != -1)
            {
                data1[curr] = v[i]; // new node inserted

                right1[s.top().fi] = curr; // the top node in stack has its right as this new node
                s.top().se++;              // the top node is now waiting for its right child

                // inserting this node in the stack
                s.push({curr, 0}); // this new node will be waiting for its left

                i++;    // index increase
                curr++; // future node pointer
            }
            else
            {
                right1[s.top().fi] = -1;
                s.top().se++; // the top node is now waiting for its right child

                i++;
            }
        }
        else if (top_state == 2)
        {
            s.pop();
        }
    }

    // for(int i=0;i<v.size();i++){
    //     if (i==0) {
    // root=curr; // root=1
    // data1[curr]=v[0];
    // s.push({curr,0}); // 0 means have to put left child
    // // 1 means has to put right child
    // // 2 means has to pop this
    // curr++;
    //     }

    //     else {
    //         if (s.empty()){
    //             // nothing and you will not reach here also
    //         }
    //         else {
    //             pair <ill,ill> p=s.top();

    //             // check the current state of the top
    //             if (p.se==0){
    //                 if (v[i]!=-1){
    //                     left1[s.top().fi]=curr;
    //                     s.top().se++;
    //                     data1[curr]=v[i];
    //                     curr++;
    //                 }
    //                 else {
    //                     left1[s.top().fi]=-1;
    //                     s.top().se++;
    //                 }
    //             }
    //             else if (p.se==1){
    //                 if (v[i]!=-1){
    //                     right1[s.top().fi]=curr;
    //                     s.top().se++;
    //                     data1[curr]=v[i];
    //                     curr++;
    //                 }
    //                 else {
    //                     right1[s.top().fi]=-1;
    //                     s.top().se++;
    //                 }
    //             }
    //             else if (p.se==2){
    //                 if (v[i]!=-1){

    //                 }
    //                 else {

    //                 }
    //             }
    //         }
    //     }
    // }

    f1(i, 1, 9)
    {
        cout << i << " --> " << data1[i] << "  " << left1[i] << "  " << right1[i] << endl;
    }
    cout << endl;
    cout << endl;
    /*

    1 --> 50  2  6
    2 --> 25  3  4
    3 --> 12  -1  -1
    4 --> 37  5  -1
    5 --> 30  -1  -1
    6 --> 75  7  9
    7 --> 62  -1  8
    8 --> 70  -1  -1
    9 --> 87  -1  -1

    */
}

void display(ill root)
{

    cout << root << "  " << data1[root] << "  " << left1[root] << "  " << right1[root] << endl;

    if (left1[root] != -1)
    {
        display(left1[root]);
    }
    if (right1[root] != -1)
    {
        display(right1[root]);
    }
}

ill solve_sum(ill root){
    if (root==-1){
        return 0;
    }

    ill lf=solve_sum(left1[root]);
    ill rt=solve_sum(right1[root]);

    return lf+rt+data1[root];
}

ill solve_size(ill root){
    if (root==-1){
        return 0;
    }

    ill lf=solve_size(left1[root]);
    ill rt=solve_size(right1[root]);

    return lf+rt+1;
}


ill solve_max(ill root){
    if (root==-1){
        return intmin; // always return identity wrt the property
    }

    ill lf=solve_max(left1[root]);
    ill rt=solve_max(right1[root]);

    return max(lf,max(rt,data1[root]));
}

ill solve_min(ill root){
    if (root==-1){
        return intmax; // always return identity wrt the property
    }

    ill lf=solve_min(left1[root]);
    ill rt=solve_min(right1[root]);

    return min(lf,min(rt,data1[root]));
}


ill solve_prod(ill root){
    if (root==-1){
        return 1; // always return identity wrt the property
    }

    ill lf=solve_prod(left1[root]);
    ill rt=solve_prod(right1[root]);

    return lf*rt*data1[root];
}


ill solve_gcd(ill root){
    if (root==-1){
        return 0; // always return identity wrt the property
    }

    ill lf=solve_gcd(left1[root]);
    ill rt=solve_gcd(right1[root]);

    return gcd(lf,gcd(rt,data1[root]));
}

ill solve_lcm(ill root){
    if (root==-1){
        return 1; // always return identity wrt the property
    }

    ill lf=solve_lcm(left1[root]);
    ill rt=solve_lcm(right1[root]);

    return lcm(lf,lcm(rt,data1[root]));
}


ill solve_height(ill root){
    if (root==-1){
        return -1; // because there is nothing there 
        // so in parent --> ht = ht(child) + 1 
        // so   -1 + 1 = 0 which means leaf has 0 height which is correct 

        // NODE ::         
        // in case of nodes   return 0;
        // in case of edges   return -1;
        
    }

    ill lf=solve_height(left1[root]); // height of left child 
    ill rt=solve_height(right1[root]); // height of right child 

    ill ht=max(lf,rt) + 1; // my height is max of ht(lf) and ht(rt)    + 1 (because of the edge I took to move from this point to the child (connecting edge) ) 

    return ht;
}


void inorder(ill root){
    if (root==-1){
        return;
    }

    
    inorder(left1[root]);
    cout<<"In - "<<root<<endl;
    inorder(right1[root]);

}

void preorder(ill root){
    if (root==-1){
        return;
    }

    cout<<"Pre - "<<root<<endl;
    preorder(left1[root]);
    preorder(right1[root]);
    
}


void postorder(ill root){
    if (root==-1){
        return;
    }
    
    postorder(left1[root]);
    postorder(right1[root]);
    cout<<"Post - "<<root<<endl;

}


void traversal(ill root){
    if (root==-1){
        return;
    }
    
    cout<<"Pre - "<<root<<endl;
    traversal(left1[root]);
    cout<<"In - "<<root<<endl;
    traversal(right1[root]);
    cout<<"Post - "<<root<<endl;

}



void level_order_traversal(ill root){
    // remove print and add children algo 
    queue <ill> q;
    q.push(root);
    q.push(-1);

    while(1){
        if (q.empty()){
            break;
        }

        ill x=q.front();
        if (x!=-1){
            q.pop(); // remove 
            cout<<x<< "  "; // print 
            if (left1[x]!=-1 ) q.push(left1[x]); // add children 1 
            if (right1[x]!=-1 ) q.push(right1[x]); // add children 2 
        }
        else {
            q.pop();
            cout<<endl;
            if (!q.empty()) { 
                q.push(-1);
            }
        }
    }

    cout<<endl;

}
// level of each node 
// 1 --> can be calculated using the above method --> by introducing a varaible curr_level and updating it on reaching -1
// 2 --> can be calculated using dfs by sending solve_level(root,0) and in the child sending solve_level(left[x],level+1) and solve_level(right[x],level+1)
// 3 --> can be calculated from the parent by storing the parent and dfs call  -->  level[child] = level[parent] + 1  and   dfs ensures that first parent is visited then child is visited 


void iterative_traversal(ill root){
    stack <pii> s;
    s.push({root,1});

    while(1){
        if (s.empty()){
            break;
        }

        ill state=s.top().se;
        ill root_at_top=s.top().fi;

        if (state==1){
            cout<<"Pre - "<<root_at_top<<endl;
            s.top().se++;
            if (left1[root_at_top] != -1) {
                s.push({left1[root_at_top],1});
            }
        }
        else if (state==2){
            cout<<"In - "<<root_at_top<<endl;
            s.top().se++;
            if (right1[root_at_top] != -1) {
                s.push({right1[root_at_top],1});
            }

        }
        else if (state==3){
            cout<<"Post - "<<root_at_top<<endl;
            s.pop();
        }   
    }

    cout<<endl;

}


ill find_x(ill root,ill x){
    if (root==-1){
        return 0;
    }

    if (data1[root]==x) {
        return 1;
    }

    ill left_check=find_x(left1[root],x);
    if (left_check==1) {
        return 1;
    }
    ill right_check=find_x(right1[root],x);
    if (right_check==1) {
        return 1;
    }

    return 0;
}


// other then cout you can store it in a vector 
ill node_to_root(ill root,ill x){
    if (root==-1){
        return 0;
    }

    if (data1[root]==x) {
        cout<<root<< "  ";
        return 1;
    }

    ill left_check=node_to_root(left1[root],x);
    if (left_check==1) {
        cout<<root<< "  ";
        return 1;
    }
    ill right_check=node_to_root(right1[root],x);
    if (right_check==1) {
        cout<<root<< "  ";
        return 1;
    }

    return 0;
}


void print_k_level_down(ill root,ill curr_level,ill k){ 
    if (root==-1){
        return;
    }

    if (curr_level==k) {
        cout<<data1[root]<< "  ";
        return; // because no need to call down because the levels will increase from here 
    }

    print_k_level_down(left1[root],curr_level+1,k);
    print_k_level_down(right1[root],curr_level+1,k);

}

void solve1(ill root,ill l,ill r,ill sum,vector <ill>& path){

    if (root==-1){ // normal base cases 
        return; // nothing to do here (because they are not the nodes )
    }

    // checking leaf or not 
    // what is the property of leaf
    // it has no child --> left and right are both -1
    // if any one is -1 then this is not root --> it has a child (1 child)

    if (left1[root]==-1 && right1[root]==-1) { // leaf
        
        // also push this value 
        path.push_back(root);
        sum=sum+data1[root];

        if (sum>=l && sum<=r){
            for(auto x: path){
                cout<<x<<"  ";
            }
            cout<<endl;
        }

        // back tracking 
        // undo all the changes you made before returning 
        path.pop_back();
        // sum=sum-data1[root]; // no need to do this because sum is not passed by reference so doing anything to sum here 
        // makes no changes in the call stacks of others 

        return;

    }

    // should be above checking it is leaf or not 
    // if (root==-1){ // normal base cases 
    //     return; // nothing to do here (because they are not the nodes )
    // }

    // 2 calls 
    // left and right 
    path.pb(root); // path will have this root 
    solve1(left1[root],l,r,sum+data1[root],path);
    solve1(right1[root],l,r,sum+data1[root],path);
    path.pop_back(); // backtracting 
 
}

int main()
{
    construct();

    display(root);

    ill res_sum=solve_sum(root);
    cout<<res_sum<<endl<<endl;

    ill res_size=solve_size(root);
    cout<<res_size<<endl<<endl;

    ill res_max=solve_max(root);
    cout<<res_max<<endl<<endl;

    ill res_min=solve_min(root);
    cout<<res_min<<endl<<endl;

    ill res_prod=solve_prod(root);
    cout<<res_prod<<endl<<endl;

    ill res_gcd=solve_gcd(root);
    cout<<res_gcd<<endl<<endl;

    ill res_lcm=solve_lcm(root);
    cout<<res_lcm<<endl<<endl;

    ill res_height=solve_height(root);
    cout<<res_height<<endl<<endl;

    inorder(root);
    cout<<endl;
    cout<<endl;

    preorder(root);
    cout<<endl;
    cout<<endl;

    postorder(root);
    cout<<endl;
    cout<<endl;

    traversal(root); // in pre post all in one (just identify there regions)
    cout<<endl;
    cout<<endl;

    level_order_traversal(root);
    cout<<endl;

    iterative_traversal(root);
    cout<<endl;

    ill x=30; // pointer = 3 
    ill check=find_x(root,x);
    cout<<check<< endl<<endl;

    // ill x=30; // pointer = 3 
    check=node_to_root(root,x);
    // cout<<check<< endl<<endl;
    if (check==1) {
        // cout<<root<< "  ";
    }
    else {
        cout<<"NOT PRESENT"<<endl;
    }

    cout<<endl;
    cout<<endl;

    ill k=2;
    ill curr_level=0;
    print_k_level_down(root,curr_level,k);

    cout<<endl;
    cout<<endl;

    
    // dont call 
    // ill from1=7;
    // ill k1=1;
    // print_k_level_far(from1,k1);

    // ill from2=8;
    // ill k2=3;
    // print_k_level_far(from2,k2);


/*

print k layer far :

method 1: 
1. get the root to node vector 
2. send k-i(-+)sth level down from all nodes sending a previous and dont go to the previous 
// as discussed in the notebook 


method 2:

public static ArrayList<Node> nodeToRootPath(Node node, int data) {
    if (node == null) {
      return new ArrayList<>();
    }

    if (node.data == data) {
      ArrayList<Node> list = new ArrayList<>();
      list.add(node);
      return list;
    }

    ArrayList<Node> llist = nodeToRootPath(node.left, data);
    if (llist.size() > 0) {
      llist.add(node);
      return llist;
    }

    ArrayList<Node> rlist = nodeToRootPath(node.right, data);
    if (rlist.size() > 0) {
      rlist.add(node);
      return rlist;
    }

    return new ArrayList<>();
}


public static void printKLevelsDown(Node node, int k) {
    if (node == null || k < 0) {
      return;
    }

    if (k == 0) {
      System.out.println(node.data);
      return;
    }

    printKLevelsDown(node.left, k - 1);
    printKLevelsDown(node.right, k - 1);
}


public static void printKNodesFar(Node node, int data, int k) {
    ArrayList<Node> path = nodeToRootPath(node, data);

    printKLevelsDown(path.get(0), k); // just k level down from here 

    for (int i = 1; i < path.size(); i++) {
      Node prev = path.get(i - 1);
      Node curr = path.get(i);

      if (i < k) {
        if (prev == curr.left) {
          printKLevelsDown(curr.right, k - i - 1);
        } else {
          printKLevelsDown(curr.left, k - i - 1);
        }
      } else if (i == k) {
        System.out.println(curr.data);
      } else {
        break;
      }
    }
  }


*/


    // CAN BE USED IN MANY PATH RELATED PROBLEMS :-->
    
    // question -> print all the paths from node to leaf whose sum of values of path is between l and r 
    vector <ill> path; 
    // current path under consideration --> current active part of dfs --> from root to a lower node only 
    ill l=-1;
    ill r=1000;
    ill sum=0;
    solve1(root,l,r,sum,path);
    cout<<endl;
    cout<<endl;


    path.clear();
    l=-1;
    r=90;
    sum=0;
    solve1(root,l,r,sum,path);
    cout<<endl;
    cout<<endl;


    return 0;
}
