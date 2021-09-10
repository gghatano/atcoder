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
  vector<double> a(N), b(N);
  for(int i = 0; i < N; i++){
    cin >> a[i] >> b[i];
  }

  double sum = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      double tmp = 0;
      tmp += (a[i] - a[j]) * (a[i] - a[j]);
      tmp += (b[i] - b[j]) * (b[i] - b[j]);

      tmp = sqrt(tmp);
      sum += tmp;
    }
  }
  cout << sum / N << endl;
}
