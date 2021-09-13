#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;

// mint
using mint = static_modint<1000000007>;

// ll int
ll INF = numeric_limits<ll>::max() / 2;
# define REP(i,n) for (int i=0;i<(n);++i)

struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    REP(i,V){
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    REP(i,V){
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};

int main(){
  // set precision (10 digit)
  cout << setprecision(10);
  int N,M; cin >> N >> M;

  graph g(N);
  REP(i, M){
    int x,y; ll z; cin >> x >> y >> z;
    x--; y--;
    g.add_edge(x,y,z);
    g.add_edge(y,x,z);
  }
  graph gg = g;

  g.dijkstra(0);
  gg.dijkstra(N-1);

  REP(i,N){
    cout << g.d[i] + gg.d[i] << endl;
  }
}
