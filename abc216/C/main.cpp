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
  ll N; cin >> N;

  string ans = "";
  while(N > 0){
    if(N%2 == 0){
      ans += "B";
      N /= 2;
    } else {
      ans += "A";
      N--;
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
