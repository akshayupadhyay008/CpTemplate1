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


// struct node{
//     int pointer; // representing this node and is unique in the tree 
//     int data; // data of this pointer can be same for 2 nodes but its place in tree is unique represented by the pointer
//     vector <ill> child; // pointer of all its children
//     // can have other data of this node 
// };

// this struct way is also correct and since the pointer are integers 1 2 3 4 5 ... so we can directly store then in vectors and arrays and take the pointers as the index of the vector or array
ill data1[N]; // 1 based index 
vector <ill> adj[N]; // child 

ill currnode; // current node pointer value 1,2,3,4.....
ill root;

void construct_tree_from_euler(){
    vector <ill> sample{10,20,50,-1,60,-1,-1,30,70,-1,80,110,130,-1,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};

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

    f1(i,1,12){
        cout<<i << "  " << data1[i]<<" -->  ";
        for(auto x:adj[i]){
            cout<<x<<"  ";
        }
        cout<<endl;
    }
    
}
/*

1  10 -->  2  5  11  
2  20 -->  3  4
3  50 -->
4  60 -->
5  30 -->  6  7  10
6  70 -->
7  80 -->  8  9
8  110 -->
9  120 -->
10  90 -->
11  40 -->  12
12  100 -->

*/

// we do not need visited because we have stored only the childs and not parent in the adj vector 
// so we never move to the previously visited node --> we move to the childs only 
// if the construction was given in the form of edges then having the visited array or having parent stored and not going to the parent eill be needed 

void display(ill root){
    cout<<root<<" --> "<<data1[root]<<endl;

    for(auto x: adj[root]){
        display(x);
    }

}


ill parent[N];

void construct_tree_from_euler_parent(){
    vector <ill> sample{10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};

    stack <ill> s;

    currnode=1;

    for(auto x:sample){
        // we are not concerned about the data 
        // the node and the position of the node in the tree is represented bu the index ie the pointer ie the currnode
        if (x!=-1){
            // push pointers in the stack because they are main, not the data 
            if (s.empty()){

                data1[currnode]=x;
                
                parent[currnode]=-1;

                root=currnode;
                s.push(currnode);
                currnode++;
            }
            else {
                data1[currnode]=x;

                adj[s.top()].pb(currnode);
                adj[currnode].pb(s.top());

                parent[currnode]=s.top();

                s.push(currnode);
                currnode++;
            }
        }
        else { // x==-1
            s.pop();
        }   
    }

    f1(i,1,12){
        cout<<i << "  " << data1[i] <<  "  " << parent[i] <<" -->  ";
        for(auto x:adj[i]){
            cout<<x<<"  ";
        }
        cout<<endl;
    }
    
}

void display_parent(ill root){
    cout<<root<<" --> "<<data1[root]<<endl;

    for(auto x: adj[root]){
        if (x != (parent[root])) { 
            display_parent(x);
        }
    }

}

ill vis[N];

void display_visited(ill root){
    vis[root]=1;
    cout<<root<<" --> "<<data1[root]<<endl;

    for(auto x: adj[root]){
        // if (x != (parent[root])) { 
        //     display_parent(x);
        // }
        if (!vis[x]){
            display_visited(x);
        }
    }

}


ill size_of_tree(ill root){
    ill subtree_size=0;

    for(auto x: adj[root]){
        subtree_size=subtree_size+size_of_tree(x);
    }

    return 1+subtree_size;
}

ill max_of_tree(ill root){
    ill mx=data1[root];

    for(auto x: adj[root]){
        mx=max(mx,max_of_tree(x));
    }

    return mx;
}
// similarly sum,prod,min,gcd,lcm, ..... any property that depends on the child of the root 
// and can be calculated if we know that for the child 


ill height_of_tree(ill root){
    ill mx_depth=0;

    for(auto x: adj[root]){
        // mx_depth=max(height_of_tree(x)+1,mx_depth);  // correct but to visualise write like :

        ill temp=1+height_of_tree(x);
        mx_depth=max(temp,mx_depth);
        // calling the depth of the child  + adding 1 because from going to the parent to the child we needed 1 edge so 1 + (child to the leaf(deepest))

    }

    return mx_depth;
}


ill dist[N]; // level -->  // or level of the node 
 

void distance_from_root(ill root,ill di){
    dist[root]=di;

    for(auto x: adj[root]){
        distance_from_root(x,di+1); // because we are going down by 1 edge so distance inc by 1 
    }

}

void euler_traversal(ill root){
    cout<<"Pre node - "<<root<<endl;

    for(auto x: adj[root]){
        cout<<"Pre edge - "<< root <<" --> "<<x<<endl;
        euler_traversal(x);
        cout<<"Post edge - "<< root <<" --> "<<x<<endl;
    }

    cout<<"Post node - "<<root<<endl;
}



void level_order_traversal(ill root){

    queue <ill> q;

    q.push(root);

    // rpa 
    // remove(store who is being removed to know his/her child) print add children 
    while(1){
        if (q.empty()){
            break;
        }

        ill x=q.front();
        q.pop();

        cout<<x<<"  ";        

        for(auto y:adj[x]){
            q.push(y);
        }
    }

}

ill level_using_bfs[N];

void level_order_linewise(ill root){
    queue<ill> q;
    
    ill curr_level=1;
    q.push(root);
    q.push(-1);

    while(1){
        if (q.empty()){
            break;
        }

        ill x=q.front();
        if (x==-1){
            q.pop();

            // q.push(-1); // only if queue is not empty otherwise infinite loop
            if (!q.empty()){
                q.push(-1);
            }

            curr_level++;
            cout<<endl;

        }
        else {
            q.pop();
            cout<<x << "  ";
            level_using_bfs[x]=curr_level;
            for(auto y:adj[x]){
                q.push(y);
            }
        }
    }


    f0(i,1,12){
        cout<<i<< " - " <<level_using_bfs[i]<<endl;
    }
    cout<<endl;

}


ill level_using_2queue[N];

void level_order_2queue(ill root){

    queue <ill> q1;
    queue <ill> q2;
    
    ill curr_level=1;

    q1.push(root);
    

    while(1){
        if (q1.empty() && q2.empty()){
            break;
        }

        if (q1.empty()) {

            
            while(1){

                if (q2.empty()){
                    break;
                }

                ill x=q2.front();
                q2.pop();

                cout<<x<<"  ";  
                level_using_2queue[x]=curr_level;

                for(auto y:adj[x]){
                    q1.push(y);
                }

            }

            
            curr_level++;

        }

        else if (q2.empty()) {

            while(1){

                if (q1.empty()){
                    break;
                }
                
                ill x=q1.front();
                q1.pop();

                cout<<x<<"  ";        
                level_using_2queue[x]=curr_level;

                for(auto y:adj[x]){
                    q2.push(y);
                }
                
            }

            curr_level++;
        }


    }
    
    cout<<endl;
    f0(i,1,12){
        cout<<i<< " - " <<level_using_2queue[i]<<endl;
    }
    cout<<endl;

}



ill level_using_2queueB[N];

void level_order_2queueB(ill root){

    queue <ill> main_queue;
    queue <ill> child_queue;

    ill curr_level=1;

    main_queue.push(root);
    
    while(1){
        if (main_queue.empty()){
            break;
        }
        
        ill x=main_queue.front();
        main_queue.pop();
        cout<<x<< "   ";
        level_using_2queueB[x]=curr_level;
        // add all the childs of the parents in the main queue in the child queue 
        for(auto y:adj[x]){
            child_queue.push(y);
        }

        // now when will level change 
        // when main_queue is empty 
        // so do the level change work when the main queue becomes empty 
        if (main_queue.empty()){
            cout<<endl;
            curr_level++;
            main_queue=child_queue;

            // empty the child queue 
            while(!child_queue.empty()) {
                child_queue.pop();
            }

        }

    }

    
    cout<<endl;
    f0(i,1,12){
        cout<<i<< " - " <<level_using_2queueB[i]<<endl;
    }
    cout<<endl;

}



// my way --> void level_order_2queueB(ill root){
// using the above function 
// store in the vector and while level changing print forward or reverse depening on even odd swiching ...

// sir 2 stack use 
// nodebook 
// void level_order_linewise_zig_zag(ill root){

// }

ill bfs_level[N];

void hi_level_using_bfs(ill root){

    queue <pii> q;
    q.push({root,1});

    // cout<<q.front().fi<< "   "<<q.front().se<<endl;

    while(1){
        if (q.empty()){
            break;
        }

        
        pair <ill,ill> p=q.front();
        ill x=p.first;
        ill le=p.second;
        bfs_level[x]=le;
        q.pop();

        for(auto y: adj[x]){
            q.push({y,le+1LL});
        }
        
    }

    cout<<endl;
    f0(i,1,12){
        cout<<i<< " - " <<bfs_level[i]<<endl;
    }
    cout<<endl;
    
}


vector <ill> mirror_adj[N];

void display_mirror(ill root){
    cout<<root<<" --> "<<data1[root]<<endl;

    for(auto x: mirror_adj[root]){
        display_mirror(x);
    }

}

void mirror(ill root){
    ill mirror_root;    
    mirror_root=root;

    f1(i,1,12) {
        mirror_adj[i]=adj[i];
        reverse(all(mirror_adj[i]));
    }

    display_mirror(mirror_root); // not display because we are traversing over adj there 
    // and we want to traverse over mirror_adj

}


void mirror_me(ill root){

    // reverse the subtrees first 
    // all the subtrees 
    for(auto x: adj[root]){
        mirror_me(x);
    }

    // then if the whole subtree are mirror 
    // then only reversing this adjacency list is left 
    reverse(all(adj[root]));

}



// here the order of doing parents work and childs work are independent
// so we can alter the 
void mirror_meB(ill root){

    // then if the whole subtree are mirror 
    // then only reversing this adjacency list is left 
    reverse(all(adj[root]));

    // reverse the subtrees first 
    // all the subtrees 
    for(auto x: adj[root]){
        mirror_meB(x);
    }
}


ill subtree_size_x[N];

ill solve_subtree_size(ill root){
    ill subtree_size=0;

    for(auto x: adj[root]){
        subtree_size=subtree_size+solve_subtree_size(x);
    }

    return subtree_size_x[root]=1+subtree_size;
}


void remove_leaf1(ill root){

    // if (subtree_size_x[root]==1) {
    //     return;   
    // } 
    // we cannot do something in this case because to delete a node we have to delete its connection from its parent 
    // adj[leaf] do not have anything so nothing to delete from here 
    // we have to delete from the parent 

    // for(auto x:adj[root]){ // checking from the parent side should the child remain or not --> connection from this child should be there or not 
    //     if (subtree_size_x[x]==1){
    //         // 1st you cannot remove from the auto for loop 
    //         // in order to remove you has to have the iterator 
    //         // now a nice thing to note --> if you are iterating like this 
    //         // for (auto it=v.begin();it!=v.end();it++) // and we keep on removing this will be wrong 
    //         // not work 
    //         // for (int i=0;i<v.size();i++){
        //           this will also be wrong 
//    }
    //         // --> the way out --> iterate backwards and keep dividing 
    //     }
    // }

    if (subtree_size_x[root]==1) {
        return;
    }  // no work here 


    auto it=adj[root].end();
    it--;

    while(1){
        ill val=*it;
        if (subtree_size_x[val] == 1){
            auto it2=it;
            // it--;
            adj[root].erase(it2);
        }
        else {
            // it--;
        }      

        if (it==adj[root].begin()){
            break;
        }

        it--;

    }

    for (auto x:adj[root]){
        remove_leaf1(x);
    }

}


// not getting this 
// doubt 
// seen 
// ill linearize_tree(ill root){
//     if (adj[root].size() == 0){
//         return root;
//     }

//     if (adj[root].size() == 1) {
//         ill x=linearize_tree(linearize_tree(adj[root][0]));
//         return x;
//     }

    
//     // ill prev=-1;
//     // for(int i=0;i<adj[root].size();i++){
//     //     if (i==0) {
//     //         prev=linearize_tree(adj[root][i]);
//     //     }
//     //     else {
            
//     //     }
//     // }
//     // not this because deletion cannot take place here 

//     // ill prev=linearize_tree(adj[root][0]);

//     // or better start from the back 
//     // auto it=adj[root].end();

//     // it--;

//     // while(1){
//     //     if (it==adj[root].begin()){

//     //     }
//     // }
//     // but we have to move forward also 
    
//     ill prev=-1;

//     for(int i=0;i<adj[root].size();i++){
//         if (i==0) {
//             prev=linearize_tree(adj[root][i]);
//         }
//         else {
//             // remove this from the adjacency list 
//             adj[prev].pb(adj[root][i]);

//         }
//     }

// }


// can also if calculated using recusion --> going deep till left with no child 
// if NO child then return THIS 
ill getEnd(ill root){

    ill t=root;
    while(1){
        if (adj[t].size()==0) {
            return t;
        }
        else {
            t=adj[t][0]; // because it has only 1 element 
        }
    }
    return 0; // for VSCODE 

}



void linearize_tree_sir(ill root){

    for(auto x: adj[root]) {
        linearize_tree_sir(x);
    }   

    while(1){
        if (adj[root].size()==1 || adj[root].size()==0){
            break;
        }

        // getting the last 
        auto it=adj[root].end();
        it--;
        ill last=*it;

        auto it2=it;
        it2--;
        ill secondlast=*it2;

        adj[root].erase(it);
        
        ill end_of__secondlast=getEnd(secondlast);
        
        adj[end_of__secondlast].pb(last);
    }

}


ill find_in_tree(ill root,ill x){
    if (data1[root]==x){
        return 1;
    }

    for(auto y: adj[root]){
        ill check_child=find_in_tree(y,x);
        if (check_child==1){
            return 1;
        }
    }


    return 0;
}


ill node_to_root(ill root,ill x){
    if (data1[root]==x) {
        // cout<<root<< "   ";
        return 1;
    }

    for(auto y:adj[root]){
        ill check_child=node_to_root(y,x);
        if (check_child==1){
            cout<<y<< "   ";
            return 1;
        }
    }

    return 0;
}

ill parent_store[N];
void calculate_parent(ill root, ill par){
    parent_store[root]=par;

    for(auto x: adj[root]){
        calculate_parent(x,root);
    }
}


void path_to_root_parent(ill x){
    
        if (parent_store[x]==-1){
            return;
        }
        else {
            cout<<x<<"  ";
            path_to_root_parent(parent_store[x]);
        }


}


// ill data_parent[N];
// void store_data_parent(ill root , ill par){
//     data_parent[root]=par;

//     for(auto y: adj[root]){
//         store_data_parent(y,data1[root]);
//     }

// }

// void path_to_root_parent_data(ill x){

//         if (data_parent[x]==-1){  // wrong   data_parent[110] makes no sense 
// and also 2 values in the tree can have same data 
// so we dont know whom it is asking for 
// so using this makes no sense -- > the question makes no sense 
//             return;
//         }
//         else {
//             cout<<x<<"  ";
//             path_to_root_parent(data_parent[x]);
//         }


// }



void path_root(ill x , vector <ill>& ans){
    
        if (parent_store[x]==-1){
            return;
        }
        else {
            // cout<<x<<"  ";
            ans.pb(x);
            path_root(parent_store[x],ans);
        }

}


ill lca_brute_force(ill x1,ill x2){
    vector <ill> path1;
    path_root(x1,path1);

    vector <ill> path2;
    path_root(x2,path2);

    reverse(all(path1));
    reverse(all(path2));

    ill ans=-1;
    if (path1.size() > path2.size()){

        f0(i,0,path2.size()){
            if (path1[i]==path2[i]){
                ans=path1[i];
            }
            else {
                break;
            }
        }
    }
    else {
        f0(i,0,path1.size()){
            if (path1[i]==path2[i]){
                ans=path2[i];
            }
            else {
                break;
            }
        }
    }

    return ans;

}

ill distance_between_node1(ill x1,ill x2){
    vector <ill> path1;
    path_root(x1,path1);

    vector <ill> path2;
    path_root(x2,path2);

    reverse(all(path1));
    reverse(all(path2));

    ill ans=-1;
    ill index=-1;
    if (path1.size() > path2.size()){

        f0(i,0,path2.size()){
            if (path1[i]==path2[i]){
                ans=path1[i];
            }
            else {
                index=i;
                break;
            }
        }

        if (index==-1) {
            index=path2.size();
        }

        ans=path1.size()+path2.size()-(2*index);
    }
    else {
        f0(i,0,path1.size()){
            if (path1[i]==path2[i]){
                ans=path2[i];
            }
            else {
                index=i;
                break;
            }
        }

        
        if (index==-1) {
            index=path1.size();
        }

        ans=path1.size()+path2.size()-(2*index);
    }

    return ans;
  
}

ill distance_between_node2(ill x1,ill x2){

    ill lca_x=lca_brute_force(x1,x2);
    // level or distance from the root already stored 
    ill ans=dist[x1]+dist[x2]-(2*dist[lca_x]);

    return ans;
}

ill root11;
ill root22;
vector <ill> adj1[N];
vector <ill> adj2[N];

ill is_two_tree_similar(ill root1,ill root2){

    if (adj1[root1] != adj2[root2]){
        return 0; // number of childs has to be same 
    }

    for(int i=0;i<adj1[root1].size();i++){
        // corressponding child subtree should be similar 
        ill checker=is_two_tree_similar(adj1[root1][i],adj2[root2][i]);
        if (checker==0){
            return 0;
        }
    }

    return 1;

}


ill is_two_tree_mirror(ill root1,ill root2){

    if (adj1[root1] != adj2[root2]){
        return 0; // number of childs has to be same 
    }

    ill sz=adj1[root1].size();

    for(int i=0;i<sz;i++){
        // corressponding child subtree should be similar 
        ill checker=is_two_tree_mirror(adj1[root1][i],adj2[root2][sz-i-1]);
        if (checker==0){
            return 0;
        }
    }

    return 1;

}



ill is_symmetric(ill root1,ill root2){ // send root1 and root1 

    // if (adj1[root1] != adj1[root1]){ // will be definitely same 
    //     return 0; // number of childs has to be same 
    // }

    ill sz=adj1[root1].size();

    for(int i=0;i<sz/2;i++){
        // corressponding child subtree should be similar 
        ill checker=is_symmetric(adj1[root1][i],adj1[root2][sz-i-1]); // same as mirror of itself 
        if (checker==0){
            return 0;
        }
    }

    return 1;

}


ill multisolver_size; // size of tree 
ill multisolver_min; // minimum value in the tree 
ill multisolver_max; // maximum value in the tree
ill multisolver_height; // maximum height of the tree 

void multisolver_traverse(ill root,ill depth){
    multisolver_size++;
    multisolver_min=min(multisolver_min,data1[root]);
    multisolver_max=max(multisolver_max,data1[root]);
    multisolver_height=max(multisolver_height,depth); // max depth is the height of the tree 

    for(auto x: adj[root]){
        multisolver_traverse(x,depth+1);
    }

}


int state;
ill predecessor;
ill successor;

void solve_pre_suc(ill root,ill data_x){
    if (state==0){
        if (data1[root]==data_x){
            state=1;
        }
        else {
            predecessor=root;
        }
    }
    else if (state==1){
        successor=root;
        state=2;
    }
    else if (state==2){
        // do nothing
    }


    for(auto x: adj[root]){
        solve_pre_suc(x,data_x);
    }


}

ill ceil_x;
ill floor_x;


void solve_ceil_floor(ill root,ill data_x){
    if (data1[root]>data_x){
        ceil_x=min(ceil_x,data1[root]);
    }
    else if (data1[root]<data_x){
        floor_x=max(floor_x,data1[root]);
    }

    for(auto x: adj[root]){
        solve_ceil_floor(x,data_x);
    }

}


ill mx_subtree_sum;

ill solve_sum(ill root){
    ill sum=data1[root];

    for(auto x: adj[root]){
        sum=sum+solve_sum(x);
    }

    mx_subtree_sum=max(sum,mx_subtree_sum);
    return sum;
}

void multisolver(){ // not returning anything but solving by just traversing 
    multisolver_size=0;
    multisolver_min=intmax;
    multisolver_max=intmin;
    multisolver_height=intmin;

    multisolver_traverse(root,0);
    cout<<multisolver_size<<endl;
    cout<<multisolver_min<<endl;
    cout<<multisolver_max<<endl;
    cout<<multisolver_height<<endl;

    cout<<endl;
    cout<<endl;


    state=0;
    predecessor=-1;
    successor=-1;
    ill data_x=120;
    solve_pre_suc(root,data_x);
    cout<<predecessor<<endl;
    cout<<successor<<endl;
    cout<<endl;
    cout<<endl;


    ceil_x=intmax;
    floor_x=intmin;
    solve_ceil_floor(root,data_x);
    cout<<ceil_x<<endl;
    cout<<floor_x<<endl;
    cout<<endl;
    cout<<endl;



    // concept : when we are returning some other thing and changing some other value to get the required answer 
    mx_subtree_sum=intmin;
    ill dummy=solve_sum(root);

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
    }
    
    cout<<root<< "   "<<height_mx1<< "   "<<height_mx2<< "   " << endl;
    diameter=max(diameter,height_mx1+height_mx2);

    return height_mx1;

}

void derive_diameter(){

    ill dummy = solve_height_subtree(root);

    cout<<endl;
    cout<<endl;
    f1(i,1,12){
        cout<<i<< "  " << ht_tree[i]<<endl;
    }
    cout<<endl;
    cout<<endl;

    ill dummy2=solve_diameter(root);
    cout<<diameter<<endl;
    cout<<endl;
    cout<<endl;

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
    display(root); // dfs on tree , preorder , euler path 

    // // parent in there in the adjacency list (in many questions )
    // // use parent array
    // construct_tree_from_euler_parent();
    // display_parent(root);

    // // using visited 
    // for(int i=0;i<=1000;i++){
    //     vis[i]=0;
    // }
    // display_visited(root);

    ill sizetree=size_of_tree(root);
    cout<<sizetree<<endl;
    
    ill mx=max_of_tree(root);
    cout<<mx<<endl;

    ill ht=height_of_tree(root); // wrt the edges maximum edges to the left (number of edges required to go to the deepest leaf)
    cout<<ht<<endl;

    distance_from_root(root,0); // equal to the level of the nodes 
    for(int i=1;i<=12;i++){
        cout<<i<< "  " << dist[i]<<endl;
    }
    cout<<endl;


    euler_traversal(root);


    level_order_traversal(root); // bfs
    cout<<endl;
    cout<<endl;

    // dfs se level is easy // -->  done dist[N] --> level  --> because level is equal to the distance from the root 

    // bfs se level 
    // using -1 indicator 
    cout<<"level_order_linewise(root);"<<endl;
    level_order_linewise(root); // print each level in the next line and store level also using this bfs 
    cout<<endl;
    cout<<endl;

    // using 2 queues 
    cout<<"level_order_2queue(root);"<<endl;
    level_order_2queue(root);
    cout<<endl;
    cout<<endl;


    cout<<"level_order_2queueB(root);" <<endl;
    level_order_2queueB(root);
    cout<<endl;
    cout<<endl;

    // level_order_linewise_zig_zag(root); // nodebook 

    hi_level_using_bfs(root);
    cout<<endl;
    cout<<endl;


    // mirror(root); // another tree which is the mirror of this 
    // cout<<endl;cout<<endl;

    
    // mirror_me(root); // transfroms this tree to mirrored tree 
    // display(root);
    // cout<<endl;cout<<endl;

    // mirror_meB(root);
    // display(root);
    // cout<<endl;cout<<endl;

    

    // // we need precalculated subtree size 
    // // in the size of tree (we can store subtree sizes as well)
    // ill dummy=solve_subtree_size(root); 
    
    // f1(i,1,12){
    //     cout<<i<< " --> " << subtree_size_x[i]<<endl;
    // }
    // cout<<endl;

    // f1(i,1,12){
    //     cout<<i<< " -->  ";
    //     for(auto y: adj[i]){
    //         cout<<y<<"  ";
    //     }
    //     cout<<endl;
    // }

    // remove_leaf1(root);
    // cout<<endl;

    // f1(i,1,12){
    //     cout<<i<< " -->  ";
    //     for(auto y: adj[i]){
    //         cout<<y<<"  ";
    //     }
    //     cout<<endl;
    // }
    
    // display(root);
    // cout<<endl;cout<<endl;

    // ill dummy2=linearize_tree(root);


    // cout<<endl<<"Calling linearizable ..... "<<endl;
    // linearize_tree_sir(root); 
    // this is O(N^2)
    // method 2 --> O(N) check later 

    // f1(i,1,12){
    //     cout<<i<< " -->  ";
    //     for(auto y: adj[i]){
    //         cout<<y<<"  ";
    //     }
    //     cout<<endl;
    // }
    // // display(root);
    // cout<<endl;cout<<endl;


    ill x=110;
    ill check=find_in_tree(root,x);

    if (check==1) {
        cout<<"Present"<<endl;
    }
    else {
        cout<<"Not Presnt"<<endl;
    }

    cout<<endl;
    // node to root path 
    check=node_to_root(root,x);
    if (check==0){
        cout<<"NOT present "<<endl;
    }
    else {
        cout<<root<<endl;
    }

    cout<<endl<<endl;
    calculate_parent(root,-1);
    f1(i,1,12){
        cout<<i << "   " << parent_store[i]<<endl;
    }


    cout<<endl<<endl;
    path_to_root_parent(8); // this is used when you give the pointer or representative of the node not the data 
// and having data makes no sense 
// because more than 1 can have same data 
// if only 1 have a data 
// then first find the indicator/representative of the data 
// and thencall the path using that 


// WRONG BEGIN
// and also 2 values in the tree can have same data 
// so we dont know whom it is asking for 
// // so using this makes no sense -- > the question makes no sense 
//     // wrt data parent 
//     store_data_parent(root,-1);
//     f1(i,1,12){
//         cout<<i << "   " << data_parent[i]<<endl;
//     }
//     cout<<endl<<endl;

//     // path_to_root_parent_data(110);
// WRONG END 



    // solution of this problem 
    // given x as data 
    // there can be multiple nodes n1,n2,n3,n4 ... 
    // return the path from n1 to root , n2 to root .... all to root 
    // one sol find representative of all and get path one by one 

    cout<<endl<<endl;
    // largest common ancestor 
    // have to pass index --> not data 
    ill x1=8;
    ill x2=10;
    ill res=lca_brute_force(x1,x2);
    cout<<res<<endl<<endl;


    ill distAns=distance_between_node1(x1,x2);
    cout<<distAns<<endl<<endl;


    ill distAns1=distance_between_node2(x1,x2);
    cout<<distAns1<<endl<<endl;


    // ill check_similar=two_similar(root,root2); // just function written above // not called 
    // ill check_mirror=two_mirror(root,root2); // just function written above // not called 
    // ill check_symmetric=two_mirror(root,root1); // just function written above // not called 
    

    multisolver();

    derive_diameter();

    return 0;
}