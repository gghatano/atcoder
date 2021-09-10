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
  ll N,M; cin >> N >> M;

  // 接するマスが奇数個
  ll ans = 0;
  if(N == 1 && M == 1){
    ans = 1;
  } else if(N == 1){
    ans = M - 2;
  } else if(M == 1){
    ans = N - 2;
  } else {
    ans = (N-2) * (M-2);
  }
  cout << ans << endl;

}
