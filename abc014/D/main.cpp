#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

// mint
using mint = static_modint<1000000007>;
// ll int
ll INF = numeric_limits<ll>::max() / 2;

vector<vector<int>> parent; // 2^k個上の親
vector<int> dist; // 深さ

int query(int x, int y){
  // xとyのLCAを返す

  if(dist[x] < dist[y]){
    return query(y,x);
  }

  int in = x;
  int out = y;

  if(dist[x] != dist[y]){
    int up = dist[x] - dist[y];
    int log_up = log2(up);
    for(ll k = log_up; k >= 0; k--){
      if((up>>k)&1){
        x = parent[k][x];
      }
    }
  }

  int lca;
  if(x == y){
    lca = x;
  } else {
    int height = parent.size();
    for(int i = height -1; i >= 0; i--){
      if(parent[i][x] != parent[i][y]){
        x = parent[i][x];
        y = parent[i][y];
      }
    }
    lca = parent[0][x];
  }

  return lca;
}

int main(){
  int N;
  cin >> N;
  vector<vector<int>> v(N);
  dist.assign(N,0);

  int root = 0;

  for(int i = 0; i < N-1; i++){
    int x,y; cin >> x >> y;
    x--; y--;
    v[x].emplace_back(y);
    v[y].emplace_back(x);
  }

  // 0からの距離
  dist[root] = 0;
  queue<int> q;
  q.push(root);

  // rootからの深さ:distを計算
  int log_N = floor(log2(N));
  parent.assign(log_N+1, vector<int>(N));

  parent[0][root] = -1;

  while(!q.empty()){
    int now = q.front();
    q.pop();

    for(int next: v.at(now)){
      if(dist[next] == 0 && next != root){
        parent[0][next] = now;
        dist[next] = dist[now] + 1;
        q.push(next);
      }
    }
  }

  // ダブリングで親を前計算
  for(int k = 0; k < log_N; k++){
    for(int i = 0; i < N; i++){
      if(parent[k][i] == -1){
        parent[k+1][i] = -1;
      } else { 
        parent[k+1][i] = parent[k][parent[k][i]];
      }
    }
  }

  int Q; cin >> Q;
  for(int i = 0; i < Q; i++){
    int x,y; cin >> x >> y;
    x--; y--;

    int lca = query(x,y);
    // cerr << x << " " << y << " " << lca << endl;
    int d = dist[x] + dist[y] - 2 * dist[lca];

    cout << d + 1 << endl;
  }
}