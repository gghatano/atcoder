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

// 約数列挙 O(√n)
vector<ll> divisor(ll n){
  vector<ll> res;
  for(ll i = 1; i * i <= n; i++){
    if(n % i == 0){
      res.push_back(i);
      if(i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

int main(){
  // set precision (10 digit)
  cout << setprecision(10);
  ll k; cin >> k;
  auto v = divisor(k);

  sort(v.begin(), v.end());

  ll ans = 0;
  for(int i = 0; i < v.size() && v[i] * v[i] <= k; i++){
    for(int j = 0; j <= i; j++){
      ll tmp = v[i] * v[j];
      if(k % tmp != 0) continue;

      ll c = k / tmp;
      if(c >= v[i]){
        ans++;
      } else {
        continue;
      }
    }
  }
  cout << ans << endl;
}

