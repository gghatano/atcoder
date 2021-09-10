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

vector<vector<ll>> v;
int ans = 0;
int N; ll K; 

void solve(vector<int> t){

  ll sum = 0;
  for(int i = 0; i < N-1; i++){
    if(i == 0){
      sum += v[0][t[i]];
    } else {
      sum += v[t[i-1]][t[i]];
    }
  }

  sum += v[t[N-2]][0];

  if(sum == K) ans++;
};

int main(){
  // set precision (10 digit)
  cout << setprecision(10);
  cin >> N >> K;
  v.assign(N, vector<ll>(N,0));

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> v[i][j];
    }
  }

  vector<int> t;
  for(int i = 1; i < N; i++){
    t.emplace_back(i);
  }

  do{
    solve(t);
  }while(next_permutation(t.begin(), t.end()));

  cout << ans << endl;
}
