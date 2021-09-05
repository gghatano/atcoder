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
  map<string, int> m;

  for(int i = 0; i < N; i++){
    string s1,s2; cin >> s1 >> s2;
    string S = s1 + "_" + s2;
    if(m.count(S) != 0){
      cout << "Yes" << endl;
      return 0;
    } else { 
      m[S] = 1;
    }
  }
  cout << "No" << endl;
  return 0;
}
