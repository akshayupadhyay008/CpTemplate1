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

/*


import java.util.*;

public class Main {
  public static class Node {
    int data;
    Node left;
    Node right;
    Node() {
    }
    Node(int data) {
      this.data = data;
    }
  }
  public static class Pair {
    Node node;
    int state;

    Pair() {
    }

    Pair(Node node, int state) {
      this.node = node;
      this.state = state;
    }
  }

  public static Node construct(Integer[]arr) {
    Node root = new Node(arr[0]);

    Stack< Pair>st = new Stack< >();
    Pair root_pair = new Pair(root, 1);

    st.push(root_pair);
    int idx = 1;

    while (st.size() > 0) {
      Pair top = st.peek();

      if (top.state == 1) {
        //waiting for left child
        top.state++;
        if (arr[idx] != null) {
          Node lc = new Node(arr[idx]);
          top.node.left = lc;

          Pair lcp = new Pair(lc, 1);
          st.push(lcp);
        }
        idx++;
      }
      else if (top.state == 2) {
        //waiting for right child
        top.state++;
        if (arr[idx] != null) {
          Node rc = new Node(arr[idx]);
          top.node.right = rc;

          Pair rcp = new Pair(rc, 1);
          st.push(rcp);
        }
        idx++;
      }
      else if (top.state == 3) {
        st.pop();
      }
    }
    return root;

  }

  public static void display(Node node) {
    if (node == null) {
      return;
    }

    String str = " <- " + node.data + " -> ";

    String left = (node.left == null) ? "." :  "" + node.left.data;
    String right = (node.right == null) ? "." : "" + node.right.data;

    str = left + str + right;

    System.out.println(str);

    display(node.left);
    display(node.right);
  }

  public static void main(String[]args) {
    Integer[]arr = {50, 25, 12, null, null, 37, 30, null, null, null, 75, 62, null, 70, null, null, 87, null, null};

    Node root = construct(arr);
  }


*/

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

  /*

      Node root = new Node(arr[0]);

      Stack< Pair>st = new Stack< >();
      Pair root_pair = new Pair(root, 1);

      st.push(root_pair);
      int idx = 1;

      while (st.size() > 0) {
        Pair top = st.peek();

        if (top.state == 1) {
          //waiting for left child
          top.state++;
          if (arr[idx] != null) {
            Node lc = new Node(arr[idx]);
            top.node.left = lc;

            Pair lcp = new Pair(lc, 1);
            st.push(lcp);
          }
          idx++;
        }
        else if (top.state == 2) {
          //waiting for right child
          top.state++;
          if (arr[idx] != null) {
            Node rc = new Node(arr[idx]);
            top.node.right = rc;

            Pair rcp = new Pair(rc, 1);
            st.push(rcp);
          }
          idx++;
        }
        else if (top.state == 3) {
          st.pop();
        }
      }
      return root;


  */

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

  if (left1[root] != -1){
    display(left1[root]);
  }
  if (right1[root] != -1){
    display(right1[root]);
  }
}

int main()
{
  construct();

  display(root);

  return 0;
}