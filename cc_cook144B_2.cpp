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

void yash()
{
  int n;
  cin >> n; 
  vector<int> v(n);
  map<int, int> mp;
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	mp[v[i]]++;
  }

  sort(all(v));

  double mean = (v[0] + v[1] + v[2]) / (float)3;
  double median = v[1];
  median -= mean;
  median *= 3;
  if(median < 0) median *= -1;

  int ans = (int)median;
  for(int i = 0; i < n; i++) {
  	for(int j = i + 1; j < n; j++) {
  		int a = v[i];
  		int b = v[j];

  		vector<int> temp;
  		temp.push_back(a); temp.push_back(b);

  		int want = (a + b) / 2;

  		int idx1 = -1, idx2 = -1;

  		int l = 0, r = n - 1;
  		while (l <= r) {
  			int mid = (l + r) / 2;

  			if(v[mid] >= want) {
  				idx1 = mid;
  				r = mid - 1;
  			}
  			else {
  				l = mid + 1;
  			}

  		}

  		l = 0, r = n - 1;
  		while (l <= r) {
  			int mid = (l + r) / 2;

  			if(v[mid] <= want) {
  				idx2 = mid;
  				l = mid + 1;
  			}
  			else {
  				r = mid - 1;
  			}
  		}

  		// idx1 < idx2

  		vector<int> temp1 = temp;
  		if(idx1 != -1) {
  			int t = 0;
  			if(v[idx1] == a)t++;
  			if(v[idx1] == b)t++;

  			temp.push_back(v[idx1]);
  			sort(all(temp));

  			if(mp[v[idx1]] > t) {
  				double mean = (a + b + v[idx1]) / (float)3;
  				double median = temp[1];

  				median -= mean;
  				median *= 3;
  				if(median < 0) median *= -1;

  				// if(median == mean) {
  				// 	pVec(temp);
  				// }
  				ans = min(ans, (int)median);
  			}
  		}

  		if(idx2 != -1) {
  			int t = 0;
  			if(v[idx2] == a)t++;
  			if(v[idx2] == b)t++;

  			temp1.push_back(v[idx2]);
  			sort(all(temp1));

  			if(mp[v[idx2]] > t) {
  				double mean = (a + b + v[idx2]) / (float)3;
  				double median = temp1[1];

  				median -= mean;
  				median *= 3;
  				if(median < 0) median *= -1;

  				// if(median == mean) {
  				// 	pVec(temp);
  				// }
  			}
  		}

  	}
  }

  cout << ans << '\n';
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  test
  yash();
  return 0;
}