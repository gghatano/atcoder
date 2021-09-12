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
  int N,M; cin >> N >> M;

  vector<int> flg(N,0);
  for(int i = 0; i < M; i++){
    int x,y; cin >> x >> y;
    x--; y--;
    if(x < y) flg[y]++;
    if(y < x) flg[x]++;
  }

  int ans = 0;
  for(int i = 0; i < N; i++){
    if(flg[i] == 1) ans++;
  }
  cout << ans << endl;
}
