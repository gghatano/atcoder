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
  mint sum = 0;
  mint sum2 = 0;
  for(int i = 0; i < N; i++){
    ll tmp; cin >> tmp;
    mint mtmp = tmp;
    sum += mtmp;
    sum2 += mtmp*mtmp;
  }

  mint ans = sum*sum - sum2;
  mint x2 = 2;
  ans *= x2.inv();
  cout << ans.val() << endl;
  

}
