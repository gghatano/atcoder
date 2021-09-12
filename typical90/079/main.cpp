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
  int H,W; cin >> H >> W;

  vector<vector<ll>> v(H, vector<ll>(W,0));
  vector<vector<ll>> w(H, vector<ll>(W,0));

  int a_odd = 0;
  int a_even = 0;
  int b_odd = 0;
  int b_even = 0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> v[i][j];
      if( (i+j) % 2 == 0){
        a_even += v[i][j];
      } else {
        a_odd += v[i][j];
      }
    }
  }
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> w[i][j];
      if( (i+j) % 2 == 0){
        b_even += w[i][j];
      } else {
        b_odd += w[i][j];
      }
    }
  }
  ll ans = 0;
  if( (b_even - b_odd) == (a_even - a_odd)){
    for(int i = 0; i < H; i++){
      for(int j = 0; j < W; j++){
        if(i < H-1 && j < W-1){
          ans += abs(w[i][j] - v[i][j]);
          v[i+1][j] += w[i][j] - v[i][j];
          v[i][j+1] += w[i][j] - v[i][j];
          v[i+1][j+1] += w[i][j] - v[i][j];
        } else {
          if(v[i][j] != w[i][j]){
            cout << "No" << endl;
            return 0;
          } else {
            continue;
          }
        }
      }
    }
  } else {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  cout << ans << endl;

}
