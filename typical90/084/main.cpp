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
  ll N; string S; cin >> N; cin >> S;
  vector<ll> v;

  char before;
  ll num = 0;
  for(int i = 0; i < S.size(); i++){
    if(i == 0){
      before = S[i];
      num = 1;
    } else if(S[i] == before){
      num++;
    } else {
      v.emplace_back(num);
      before = S[i];
      num = 1;
    }

  }
  if(num > 0){
    v.emplace_back(num);
  }

  ll ans = N * (N-1);
  ans /= 2;

  for(auto vv: v){
    ll tmp = vv * (vv-1);
    tmp /= 2;
    ans -= tmp;
  }
  cout << ans << endl;
}
