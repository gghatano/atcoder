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

  // 現状 + 1行での最大値
  ll line_max = 0;
  ll now = 0;
  ll line_sum = 0;
  ll ans = 0;

  int N; cin >> N;
  for(int i = 0; i< N; i++){
    ll tmp; cin >> tmp;
    line_sum += tmp;

    line_max = max(line_max, line_sum);

    ans = max(ans, now + line_max);

    now += line_sum;
  }
  ans = max(ans, now);

  cout << ans << endl;
}
