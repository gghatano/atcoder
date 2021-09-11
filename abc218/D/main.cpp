#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

// mint
using mint = static_modint<1000000007>;
// ll int
ll INF = numeric_limits<ll>::max() / 2;

int main(){
  // set precision (10 digit)
  cout << setprecision(10);
  int N; cin >> N;

  map<pll, int> m;
  vector<pll> v(N);

  for(int i = 0; i < N; i++){
    ll x,y; cin >> x >> y;
    v[i] = make_pair(x,y);
    m[make_pair(x,y)] = 1;
  }
  cerr << v.size() << endl;

  ll ans = 0;
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      ll x1 = v[i].first;
      ll y1 = v[i].second;
      ll x2 = v[j].first;
      ll y2 = v[j].second;

      if(x1 > x2 || y1 > y2){
        ll x3 = x1; ll y3 = y2;
        ll x4 = x2; ll y4 = y1;

        if(m[make_pair(x3,y3)] == 1 && m[make_pair(x4,y4)] == 1){
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}

