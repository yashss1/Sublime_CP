//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<vector<int>> factors;
void preCompute() {
	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N; j+= i) {
			factors[j].push_back(i);
		}
	}
}

int n;
vector<int> v(N);
vector<int> previous(N, 0);

void go(int i) {
	if(i == n) {
		return;
	}

	vector<int> temp = factors[v[i]];
	for(int j = 0; j < temp.size(); j++) {
		if(previous[temp[j] - 1] == 0 && temp[j] != 1) {
			previous[temp[j]] = 0;
		}else {
			previous[temp[j]] = previous[temp[j] - 1] + 1;
		}
  	}

  	for(int i = 0; i <= n; i++) {
  		cout << previous[i] << ' ';
  	}cout << "\n";

  	go(i + 1);
}

void yash()
{
  
  cin >> n; 
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
  	cout << v[i] << " -> ";
  	pVec(factors[v[i]]);
  }
  cout << "\n\n";


  go(0);
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  factors.resize(N);
  preCompute();

  // test
  yash();
  return 0;
}