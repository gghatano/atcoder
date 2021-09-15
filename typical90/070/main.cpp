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
  int N; cin >> N;
  vector<ll> x(N), y(N);
  for(int i = 0; i < N; i++){
    cin >> x[i] >> y[i];
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  // 3 -> 1
  // 4 -> 2
  ll ans_x = x[N/2];
  ll ans_y = y[N/2];
  ll ans = 0;
  for(int i = 0; i < N; i++){
    ans += abs(x[i] - ans_x);
    ans += abs(y[i] - ans_y);
  }
  cout << ans << endl;
}
