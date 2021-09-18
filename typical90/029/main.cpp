#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

// mint
using mint = static_modint<1000000007>;
// ll int
// ll INF = numeric_limits<ll>::max() / 2;
using S = long long;
using F = long long;
 
const S INF = 8e18;
const F ID = 8e18;
 
S op(S a, S b){ return std::max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }
 
int main(){
  int W,N; cin >> W >> N;
  vector<S> v(W+1);
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

  for(int i = 0; i < N; i++){
    int x,y; cin >> x >> y;
    auto ans = seg.prod(x, y+1);
    cout << ans+1 << endl;

    seg.apply(x, y+1, ans+1);
  }


}

