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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(10);

  set<ll> st;

  ll L; int Q; cin >> L >> Q;

  st.insert(0);
  st.insert(L);

  while(Q--){
    int c; ll x; cin >> c >> x;

    if(c == 1){
      st.insert(x);
    } else {
      auto index = st.lower_bound(x);
      auto before = prev(index);
      cout << *index - *before << endl;

    }

  }
}
