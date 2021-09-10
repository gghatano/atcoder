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

  vector<ll> v(N+1,0);

  ll ans = 0;
  map<ll,ll> m;
  m[0] = 1;

  ll sum = 0;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;

    if(i%2 == 1){
      tmp = -1 * tmp;
    }
    sum += tmp;

    ans += m[sum];
    m[sum] += 1;
  }
  cout << ans << endl;
}
