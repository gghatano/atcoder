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
  int N,K; cin >> N >> K;
  int M = 5000;
  vector<vector<int>> A(M+1, vector<int>(M+1, 0));

  for(int i = 0; i < N; i++){
    int x,y; cin >> x >> y;

    int xmin = max(0, x-K);
    int xmax = min(M, x+K+1);
    int ymin = max(0, y-K);
    int ymax = min(M, y+K+1);

    A[xmax][ymax]++;
    A[xmax][ymin]--;
    A[xmin][ymax]--;
    A[xmin][ymin]++;
  }

  for(int i = 0; i <= M; i++){
    for(int j = 1; j <= M; j++){
      A[i][j] += A[i][j-1];
    }
  }
  for(int j = 0; j <= M; j++){
    for(int i = 1; i <= M; i++){
      A[i][j] += A[i-1][j];
    }
  }

  int ans = 0;
  for(int i = 0; i <= M; i++){
    for(int j = 0; j <= M; j++){
      ans = max(ans, A[i][j]);
    }
  }
  cout << ans << endl;


}
