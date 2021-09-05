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

vector<int> compress(vector<int> v){
  sort(v.begin(), v.end());

  vector<int> ret;
  int before;
  for(int i = 0; i < v.size(); i++){
    if(i == 0){
      before = v[i];
      ret.emplace_back(before);
    } else {
      if(before == v[i]){
        continue;
      } else {
        ret.emplace_back(v[i]);
        before = v[i];
      }
    }
  }

  return ret;
}

int main(){
  // set precision (10 digit)
  cout << setprecision(10);

  int N,M; cin >> N >> M;

  vector<vector<int>> v(N);

  for(int i = 0; i < M; i++){
    int k; cin >> k;
    int before;
    for(int j = 0; j < k; j++){
      if(j == 0){
        cin >> before;
        before--;
      } else {
        int tmp; cin >> tmp;
        tmp--;
        v[tmp].emplace_back(before);
        before = tmp;
      }
    }
  }

  // 前処理
  for(int i = 0; i < N; i++){
    // v[i] = compress(v[i]);
  }

  // 入次数の確認
  vector<int> in(N,0);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < v[i].size(); j++){
      in[v[i][j]]++;
    }
  }

  queue<int> que;
  for(int i = 0; i < N; i++){
    // cerr << i << " " << in[i] << endl;
    if(in[i] == 0){
      que.push(i);
    }
  }

  int size = que.size();

  // トポロジカルソート判定可能性 
  while(!que.empty()){
    int now = que.front();
    que.pop();

    for(auto next: v[now]){
      in[next]--;
      // 入次数が0になったら候補に追加する
      if(in[next] == 0){
        que.push(next);
        size++;
      } else {

      }
    }
  }

  if(size == N){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


}
