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
  vector<ll> A(N), B(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) cin >> B[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  ll ans = 0;
  for(int i = 0; i < N; i++){
    ans += abs(A[i] - B[i]);
  }
  cout << ans << endl;
}
