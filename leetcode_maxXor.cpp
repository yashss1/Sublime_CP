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

/*
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/

struct node{
	// map<char, node*> mp;
	vector<node*> mp;
	bool done;
	node() {
        mp.assign(2, nullptr);
		done = false;
	}
};
node* root;

void insert(int x) {
	node* curr = root;
	string s;
	for(int i = 31; i>=0; i--) {
		s.push_back(((x >> i) & 1) + '0');
	}
	for(int i = 0; i < s.size(); i++) {
		if(curr->mp[s[i] - '0'] == nullptr) {
			curr -> mp[s[i] - '0'] = new node();
		}
		curr = curr -> mp[s[i] - '0'];
	} 
	curr -> done = true;
}

int mxXor(int x) {
	node* curr = root;
	string s;
	for(int i = 31; i>=0; i--) {
		s.push_back(((x >> i) & 1) + '0');
	}

	string ans = "";
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '0') {
			if(curr -> mp[1]) {
				curr = curr -> mp[1];
				ans += "1";
			}
			else {
				if(curr -> mp[0]) {
					curr = curr -> mp[0];
					ans += "0";
				}
				else {
				 	return -1;
				}
			}
		}
		else {
			if(curr -> mp[0]) {
				curr = curr -> mp[0];
				ans += "1";
			}
			else {
				if(curr -> mp[1]) {
					curr = curr -> mp[1];
					ans += "0";
				}
				else {
				 	return -1;
				}
			}
		}
	}	 

	int res = 0;
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++) {
		if(ans[i] == '1') {
			res += (int)(1 << i);
		}
	}

	return res;
}

void yash()
{
  int n;
  cin >> n; 
  vector<int> v(n);

  root = new node();
  for(int i = 0; i < n; i++) {
  	cin >> v[i];
  	insert(v[i]);
  }

  int mx = 0;
  for(int i = 0; i < n; i++) {
  	int temp = mxXor(v[i]);
  	mx = max(mx, temp);
  }


  cout << mx << '\n';
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  // test
  yash();
  return 0;
}