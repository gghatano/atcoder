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
}
