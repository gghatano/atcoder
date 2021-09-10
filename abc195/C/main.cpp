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
  // 1,000以上: 1個
  // 1,000,000以上: 2個
  // 1,000,000,000以上:3個
  // 1,000,000,000,000以上:4個
  // 1,000,000,000,000,000以上:5個
  ll ans = 0;

  ll N; cin >> N;
  ll tmp;
  cerr << N << endl;
  tmp = (N - 1000000000000000 + 1) * 5;
  if(tmp > 0) ans += tmp;
  N %= 1000000000000000;
  
  tmp = (N - 1000000000000 + 1) * 4;
  if(tmp > 0) ans += tmp;
  N %= 1000000000000;

  tmp = (N - 1000000000 + 1) * 3;
  if(tmp > 0) ans += tmp;
  N %= 1000000000;

  tmp = (N - 1000000 + 1) * 2;
  if(tmp > 0) ans += tmp;
  N %= 1000000;

  tmp = (N - 1000 + 1) * 1;
  if(tmp > 0) ans += tmp;
  N %= 1000;


  cout << ans << endl;
}
