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
  int N; ll K; cin >> N >> K;
  vector<ll> v(N);

  ll sum = 0;
  ll time = 0;
  for(int i = 0; i < N; i++){
    cin >> v[i];
    ll tmp = v[i] * (v[i] + 1);
    sum += tmp / 2;
    time += v[i] + 1;
  }

  if(time <= K){
    cout << sum << endl;
    return 0;
  }

  ll left = 0;
  ll right = 10000000000;
  ll mid;
  // mid 以上の要素の和を数えるとK個以上、なmidの最大値
  while(right - left > 1){
    mid = (right + left) / 2;

    ll s = 0;
    // mid ... A[i] までの要素数
    for(int i = 0; i < N; i++){
      if(mid > v[i]) continue;
      s += v[i] - mid + 1;
    }

    if(s >= K){
      left = mid;
    } else {
      right = mid;
    }
  }

  cerr << left << endl;

  // left+1 ~ A[i] の和を求める
  ll ans = 0;
  ll num = 0;
  for(int i = 0; i < N; i++){
    if(left + 1 > v[i]) continue;
    ll tmp_num = v[i] - (left+1) + 1;
    num += tmp_num;
    ll tmp_ans = (v[i] + left + 1) * tmp_num;
    tmp_ans /= 2;
    ans += tmp_ans;
  } 
  ans += (K - num) * left;

  cout << ans << endl;

}
