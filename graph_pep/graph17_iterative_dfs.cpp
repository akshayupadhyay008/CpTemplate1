#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Edge
{
public:
  int src = 0;
  int nbr = 0;
  int wt = 0;


  Edge(int src, int nbr, int wt)
  {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;

  }
};
class Pair {
public:
  int src = 0;
  string psf = "";
  Pair(int src, string psf) {
    this->src = src;
    this->psf = psf;
  }
};

int main() {

  int vtces;
  cin >> vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());


  int edges;
  cin >> edges;

  for (int i = 0; i < edges; i++ ) {
    int u, v, w;
    cin >> u >> v >> w;

    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));
  }
  int src;
  cin >> src;

  vector<bool>visited(vtces, false);
  stack<Pair> st;
  string s = to_string(src);
  st.push(Pair(src, s));
  while (st.size() != 0) {
    Pair rem = st.top();
    st.pop();
    if (visited[rem.src] == true) {
      continue;
    }
    visited[rem.src] = true;
    cout << rem.src << "@" << rem.psf << endl;
    for (Edge e : graph[rem.src]) {
      string s1 = to_string(e.nbr);
      st.push(Pair(e.nbr, rem.psf + s1));
    }
  }
  return 0;
}