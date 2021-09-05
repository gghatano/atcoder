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
  double x; cin >> x;
  cerr << x << endl;

  int xx =  (int)(x * 10) % 10;
  int xxx = (int)(x * 10) / 10; 

  if(xx <= 2){
    cout << to_string(xxx) << "-" << endl;
  } else if(xx <= 6){
    cout << to_string(xxx) << endl;
  } else {
    cout << to_string(xxx) << "+" << endl;
  }
}
