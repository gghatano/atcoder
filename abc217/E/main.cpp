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

template<class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int main(){
  // set precision (10 digit)
  cout << setprecision(10);
  int Q; cin >> Q;

  queue<ll> q;
  MinHeap<ll> pq;

  while(Q--){
    int t; cin >> t;
    if(t == 1){
      ll x; cin >> x;
      q.push(x);
    } else if(t == 2){
      if(pq.size() > 0){
        cout << pq.top() << endl;
        pq.pop();
      } else {
        cout << q.front() << endl;
        q.pop();
      }
    } else {
      while(q.size() > 0){
        ll tmp = q.front();
        q.pop();
        pq.push(tmp);
      }
    }
  }
}
