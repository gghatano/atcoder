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
  int N,S; cin >> N >> S;

  vector<int> A(N), B(N);
  for(int i = 0; i < N; i++){
    cin >> A[i] >> B[i];
  }

  // dp[i][j] : i個目まで検討、和がj、-1なら買えていない、それ以外なら一つ前の和の値
  vector<vector<int>> dp(N+1, vector<int>(S+1, -1));
  // before[i][j]：直前に何を買ったか
  vector<vector<string>> before(N+1, vector<string>(S+1,""));

  dp[0][0] = 0;
  before[0][0] = "S";
  for(int i = 0; i < N; i++){
    for(int j = 0; j <= S; j++){
      // cerr << "i: " << i << " j: " << j << endl;
      if(dp[i][j] != -1){
        if(j+A[i] <= S && dp[i+1][j+A[i]] == -1){
          dp[i+1][j+A[i]] = j;
          before[i+1][j+A[i]] = "A";
        }
        if(j+B[i]<= S && dp[i+1][j+B[i]] == -1){
          dp[i+1][j+B[i]] = j;
          before[i+1][j+B[i]] = "B";
        }
      }
    }
  }

  if(dp[N][S] == -1){
    cout << "Impossible" << endl;
    return 0;
  } else {
    // 復元する
    string ans = "";
    int now = S;
    for(int i = N; i > 0; i--){
      ans += before[i][now];
      now = dp[i][now];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
}
