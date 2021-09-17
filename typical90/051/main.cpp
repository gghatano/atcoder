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

map<int, vector<ll>> calc(vector<ll> x){
  // map[要素数] = (ソートされた金額のベクトル)

  map<int, vector<ll>> ret;

  int N = x.size();
  for(int i = 0; i < (1 << N); i++){
    int size = 0;
    ll val = 0;
    for(int j = 0; j < N; j++){
      if(i & (1<<j)){
        size++;
        val += x[j];
      }
    }
    ret[size].emplace_back(val);
  }

  for(auto mm: ret){
    auto tmp = mm.second;
    sort(tmp.begin(), tmp.end());
    ret[mm.first] = tmp;
  }


  return ret;
}

int main(){
  // set precision (10 digit)
  cout << setprecision(10);
  int N,K; ll P; cin >> N >> K >> P;

  vector<ll> A,B;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    if(i < N/2){
      A.emplace_back(tmp);
    } else {
      B.emplace_back(tmp);
    }
  }

  cerr << A.size() << endl;
  auto AA = calc(A);
  auto BB = calc(B);

  ll ans = 0;
  for(auto aa: AA){
    int size = aa.first;
    auto cost_vec = aa.second;

    if(size > K) break;

    int target = K - size;
    auto target_vec = BB[target];

    for(auto cost : cost_vec){
      if(cost > P) break;
      ll max_val = P - cost;
      // max_val を超えた最初のインデックス
      ll num = upper_bound(target_vec.begin(), target_vec.end(), max_val) - target_vec.begin();
      ans += num;
    }

  } 
  cout << ans << endl;


}
