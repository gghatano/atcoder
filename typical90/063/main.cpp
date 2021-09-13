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

  vector<vector<int>> v(H, vector<int>(W));
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> v[i][j];
    }
  }

  int ans = 1;
  for(int i = 1; i < (1<<H); i++){
    map<int,int> m;
    for(int k = 0; k < W; k++){
      bool flg = false;
      bool all_equal = true;
      int num;
      for(int j = 0; j < H; j++){
        if(i & (1 << j)){
          if(!flg){
            num = v[j][k];
            flg = true;
          } else {
            if(v[j][k] != num){
              all_equal = false;
            }
          }
        } else {
          continue;
        }
        if(!all_equal) break;
      }
      if(all_equal) m[num]++;
    }
    int max_val = 0;

    int val = -1;

    for(auto mm: m){
      if(max_val < mm.second){
        max_val = max(max_val, mm.second);
        val = mm.first;
      }
    }

    // cerr << i << " " << val << " " << max_val << endl;

    ans = max(ans, max_val * __builtin_popcount(i));
  }
  cout << ans << endl;
}
