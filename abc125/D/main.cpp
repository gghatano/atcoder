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

  int minus_num = 0;
  ll sum = 0;
  ll abs_min = INF; 

  int N; cin >> N;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    if(tmp < 0){
      minus_num++;
    }

    abs_min = min(abs_min, abs(tmp));

    sum += abs(tmp);
  }

  ll ans = 0;
  if(minus_num % 2 == 0){
    ans = sum;
  } else {
    ans = sum - 2 * abs_min;
  }
  cout << ans << endl;
}
