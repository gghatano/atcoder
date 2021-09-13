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

int main(){
  // set precision (10 digit)
  cout << setprecision(10);
  int N,M; cin >> N >> M;
  scc_graph g(N);

  for(int i = 0; i < M; i++){
    int x,y; cin >> x >> y;
    x--; y--;
    g.add_edge(x,y);
  }

  auto list = g.scc();

  ll ans = 0;
  for(auto l : list){
    // cerr << l.size() << endl;
    ll tmp = l.size() * (l.size() - 1);
    tmp /= 2;
    ans += tmp;
  }
  cout << ans << endl;
}
