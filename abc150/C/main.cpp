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
  vector<int> P(N), Q(N);

  for(int i = 0; i < N; i++){
    cin >> P[i];
  }
  for(int i = 0; i < N; i++){
    cin >> Q[i];
  }

  int index = 0;
  vector<int> v;
  for(int i = 1; i <= N; i++){
    v.emplace_back(i);
  }
  int p_order, q_order;
  do{
    int sum = 0;
    for(int i = 0; i < N; i++){
      if(v[i] == P[i]) sum++;
    }
    if(sum == N) p_order = index;

    sum = 0;
    for(int i = 0; i < N; i++){
      if(v[i] == Q[i]) sum++;
    }
    if(sum == N) q_order = index;

    index++;

  } while(next_permutation(v.begin(), v.end()));

  cout << abs(p_order - q_order) << endl;
}
