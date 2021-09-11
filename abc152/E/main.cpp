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

template<typename T>
map<T, ll> prime_factorize(T x){
  map<T, ll> res;

  while(x%2==0){
    x/=2;
    res[2]++;
  }

  for(ll i=3;i*i<=x;i+=2){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}

int main(){
  // set precision (10 digit)
  cout << setprecision(10);

  int N; cin >> N;
  vector<mint> v(N);

  map<ll,ll> val;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    v[i] = tmp;
    auto t = prime_factorize(tmp);

    for(auto mm: t){
      ll x = mm.first;
      ll y = mm.second;

      val[x] = max(val[x], y);
    }
  }

  mint vv = 1;
  for(auto mm : val){
    mint x = mm.first;
    ll y = mm.second;
    vv *= x.pow(y);
  }

  mint ans = 0;
  for(int i = 0; i < N; i++){
    ans += vv * v[i].inv();
  }

  cout << ans.val() << endl;
}
